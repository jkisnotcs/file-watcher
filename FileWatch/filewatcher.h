#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#pragma execution_character_set("utf-8")

#include <QMessageBox>
#include <QMetaType>
#include <QThread>
#include <QDebug>

#include <windows.h>
#include <tchar.h>

/*
FILE_NOTIFY_CHANGE_FILE_NAME    在监视的目录或子树中的任何文件名更改都会导致更改通知等待操作返回。
                                更改包括重命名，创建或删除文件名。
FILE_NOTIFY_CHANGE_DIR_NAME     在监视的目录或子树中的任何目录名更改都会导致更改通知等待操作返回。
                                更改包括创建或删除目录。
FILE_NOTIFY_CHANGE_ATTRIBUTES   被监视的目录或子树中的任何属性更改都会导致更改通知等待操作返回。
FILE_NOTIFY_CHANGE_SIZE         监视目录或子树中任何文件大小的更改都会导致更改通知等待操作返回。
                                仅当文件写入磁盘时，操作系统才会检测到文件大小的变化。
                                对于使用大量缓存的操作系统，仅在充分刷新了缓存后才进行检测。

FILE_NOTIFY_CHANGE_LAST_WRITE   对监视目录或子树中文件的最后写入时间的任何更改都会导致更改通知等待操作返回。
                                仅当文件写入磁盘时，操作系统才会检测到上次写入时间的更改。
FILE_NOTIFY_CHANGE_LAST_ACCESS  对监视目录或子树中文件的上次访问时间的任何更改都会导致更改通知等待操作返回。
                                对于使用大量缓存的操作系统，仅在充分刷新了缓存后才进行检测。
FILE_NOTIFY_CHANGE_CREATION     对监视的目录或子树中的文件的创建时间的任何更改都会导致更改通知等待操作返回。

FILE_NOTIFY_CHANGE_SECURITY     监视的目录或子树中的任何安全描述符更改都会导致更改通知等待操作返回。
*/

//
// 监控事件类型
//

enum ActionType
{
    ActionNone = 0,
    ActionAdd = 1,            // 创建
    ActionRemove = 2,         // 删除
    ActionModify = 4,         // 修改
    ActionRename = 8,         // 重命名

    ActionAll = ActionAdd | ActionRemove | ActionModify | ActionRename,
};

//
// 文件通知类型
//

enum NotifyType
{
    NotifyNone = 0,
    NotifyFile = FILE_NOTIFY_CHANGE_FILE_NAME,
    NotifyDir = FILE_NOTIFY_CHANGE_DIR_NAME,
    NotifyAttribute = FILE_NOTIFY_CHANGE_ATTRIBUTES,
    NotifySize = FILE_NOTIFY_CHANGE_SIZE,
    NotifyTimes = FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_LAST_ACCESS | FILE_NOTIFY_CHANGE_CREATION,
    NotifySecurity = FILE_NOTIFY_CHANGE_SECURITY,

    NotifyAll = NotifyFile | NotifyDir | NotifyAttribute | NotifySize | NotifyTimes | NotifySecurity,
};

//
// 监控数据
//

class WatchData
{
public:
    ActionType action;          // 事件类型
    QString path;               // 路径
    QString oldFilename;        // 旧文件名
    QString filename;           // 当前文件名

    WatchData()
    {


    }
};
// 多线程支持
Q_DECLARE_METATYPE(WatchData);

//
// 监控任务信息
//

struct TaskInfo
{
    QString path;               // 路径
    //ActionType act;             // 监控动作类型
    //NotifyType flags;           // 监控标记
    UINT act;                   // 监控动作类型
    UINT flags;                 // 监控标记
    QStringList ignoreFiles;    // 忽略的文件列表

    TaskInfo()
    {
        // 默认监控所有事件
        act = ActionAll;

        // 默认接收所有通知
        flags = NotifyAll;
    }

    // 判断信息是否正确，能否创建有效任务
    bool isValid()const
    {
        return !path.isEmpty() && act != 0 && flags != 0;
    }
};
// 多线程支持
Q_DECLARE_METATYPE(TaskInfo);

//
// 监控类
//

class FileWatcher : public QThread
{
    Q_OBJECT

public:
    FileWatcher(QObject *parent = nullptr) : QThread(parent), m_info(), m_hFile(nullptr)
    {
    }

    FileWatcher(QObject* parent, const TaskInfo& info) : QThread(parent), m_info(info), m_hFile(nullptr)
    {
    }

    // 设置监控路径
    bool setInfomation(TaskInfo info)
    {
        // 运行状态不能设置属性
        if (this->isRunning()) {
            qDebug() << "set infomation failed.";
            return false;
        }

        m_info = info;

        return true;
    }

    // 获取监控任务信息
    TaskInfo infomation()const
    {
        return m_info;
    }

    // 开始监控
    bool startWatch()
    {
        if (!m_info.isValid()) {
            return false;
        }

        // 打开文件夹
        m_hFile = ::CreateFile(
            m_info.path.toStdWString().c_str(),   // 文件夹路径
            FILE_LIST_DIRECTORY,                  // 访问权限
            FILE_SHARE_READ | FILE_SHARE_WRITE,   // 共享读和写
            NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

        // 文件打开失败
        if (m_hFile == nullptr || m_hFile == INVALID_HANDLE_VALUE) {
            qDebug() << "目录访问失败。";
            return false;
        }

        // 启动线程
        QThread::start();

        return true;
    }

    // 停止监控
    void stopWatch()
    {
        // 停止线程
        if(this->isRunning()) {
            QThread::terminate();
            QThread::wait();

            qDebug() << "线程结束：" << m_info.path;
        }

        // 关闭文件
        if(m_hFile) {
            CloseHandle(m_hFile);
            m_hFile = nullptr;
        }
    }

protected:
    // 重载 run() 执行监控
    void run() override
    {
        BYTE                     szBuffer[2048] = {};
        DWORD                    returned       = 0;
        DWORD                    dwOffset;
        FILE_NOTIFY_INFORMATION* pInfo          = NULL;

        WatchData data;
        data.path = m_info.path;

        qDebug() << "线程开始：" << m_info.path;

        while (this->isRunning()) {

            // 初始化读取
            dwOffset = 0;
            memset(szBuffer, 0, sizeof(szBuffer));

            // 读取数据
            ReadDirectoryChangesW(m_hFile, szBuffer, sizeof(szBuffer), false, (UINT) m_info.flags, &returned, NULL, NULL);
            qDebug() << m_info.path <<  "read" << returned;

            bool ok = true;

            do {
                pInfo = (FILE_NOTIFY_INFORMATION*)&szBuffer[dwOffset];
                //qDebug() << "File Size: " << toQStr(pInfo);

                //判断事件类型，包装起来
                switch(pInfo->Action) {
                case FILE_ACTION_ADDED:
                    //qDebug() << "new file" << toQStr(pInfo);
                    data.action = ActionAdd;
                    data.filename = toQStr(pInfo);
                    break;
                case FILE_ACTION_REMOVED:
                    //qDebug() << "del file" << toQStr(pInfo);
                    data.action = ActionRemove;
                    data.filename = toQStr(pInfo);
                    break;
                case FILE_ACTION_MODIFIED:
                    //qDebug() << "modified" << toQStr(pInfo);
                    data.action = ActionModify;
                    data.filename = toQStr(pInfo);
                    break;
                case FILE_ACTION_RENAMED_OLD_NAME:
                    //qDebug() << "old name" << toQStr(pInfo);
                    data.oldFilename = toQStr(pInfo);
                    break;
                case FILE_ACTION_RENAMED_NEW_NAME:
                    //qDebug() << "new name" << toQStr(pInfo);
                    data.action = ActionRename;
                    data.filename = toQStr(pInfo);
                    break;
                default:
                    qDebug() << "unknown action.";
                    ok = false;
                    break;
                }

                // 可以发送信号事件
                if (ok) {
                    // 文件过滤
                    for(auto s : m_info.ignoreFiles) {
                        if(s.compare(data.filename, Qt::CaseInsensitive) == 0) {
                            ok = false;
                        }
                    }

                    if(ok) {
                        emit OnWatch(data);
                    }
                }

                // 移动到下一个信息位置
                dwOffset += pInfo->NextEntryOffset;

            } while (pInfo->NextEntryOffset != 0);
        }

        //qDebug() << "线程结束：" << m_info.path;
    }

signals:
    // 监控事件
    void OnWatch(const WatchData& data);

private:
    TaskInfo m_info;    // 任务信息
    HANDLE m_hFile;     // 文件或者目录句柄

    // 线程函数
    //static DWORD WINAPI threadFunction(LPVOID lpThreadParameter);

    // 转换到 QString
    QString toQStr(FILE_NOTIFY_INFORMATION* pInfo)
    {
        //return QString::fromWCharArray(pInfo->FileName, pInfo->FileNameLength);////bug
        return QString::fromStdWString(pInfo->FileName);//ok
    }
};

#endif // FILEWATCHER_H
