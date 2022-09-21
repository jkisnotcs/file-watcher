#include "filewatcher.h"
#include <QDebug>

#if 0

FileWatcher::FileWatcher(QObject *parent) : QThread(parent)
{

    qRegisterMetaType<WatchData>("WatchData");
    qRegisterMetaType<WatchData>("WatchData&");
    //qRegisterMetaType<WatchData>("WatchData const&");

    //qRegisterMetaType<QSharedPointer<MyStruct>>("QSharedPointer<MyStruct>");  //pointer

}

// 开始监控
int FileWatcher::start(LPCTSTR szPath)
{
    m_param.watcher = this;

    // 打开文件夹
    m_param.hFile = ::CreateFile(
        szPath,                               // 文件夹路径
        FILE_LIST_DIRECTORY,                  // 访问权限
        FILE_SHARE_READ | FILE_SHARE_WRITE,   // 共享读和写
        NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

    m_param.flags = FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_ATTRIBUTES |
            FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_LAST_ACCESS |
            FILE_NOTIFY_CHANGE_CREATION | FILE_NOTIFY_CHANGE_SECURITY;

    m_param.running = true;

    // 创建工作线程
    //hThread = CreateThread(nullptr, 0, threadFunction, &m_param, 0, 0);
    QThread::start();

    return 0;
}

// 停止监控
//void FileWatcher::stop()
//{
//    if (hThread) {
//        m_param.running = false;

//        TerminateThread(hThread, 0);

//        CloseHandle(m_param.hFile);
//        m_param.hFile = nullptr;
//        m_param.flags = 0;
//    }
//    qDebug() << "thread stop.";
//}

void FileWatcher::run()
{
    WATCH_PARAM* pParam = &m_param;// (WATCH_PARAM*) lpThreadParameter;
    BYTE                     szBuffer[4096] = {};
    DWORD                    returned       = 0;
    DWORD                    dwOffset;
    FILE_NOTIFY_INFORMATION* pInfo          = NULL;

    WatchData data;

    qDebug() << "thread start.";

    while (pParam->running) {

        // 初始化读取
        dwOffset = 0;
        memset(szBuffer, 0, sizeof(szBuffer));

        // 读取数据
        ReadDirectoryChangesW(pParam->hFile, szBuffer, sizeof(szBuffer), false, pParam->flags, &returned, NULL, NULL);
        qDebug() << "read" << returned;

        do {
            pInfo = (FILE_NOTIFY_INFORMATION*)&szBuffer[dwOffset];

            qDebug() << "File Size: " << QString::fromStdWString(pInfo->FileName);

            switch(pInfo->Action) {
            case FILE_ACTION_ADDED:
                //qDebug() << "new file" << QString::fromStdWString(pInfo->FileName);
                data.action = ActionType::Add;
                data.filename = QString::fromStdWString(pInfo->FileName);
                break;
            case FILE_ACTION_REMOVED:
                //qDebug() << "del file" << QString::fromStdWString(pInfo->FileName);
                data.action = ActionType::Remove;
                data.filename = QString::fromStdWString(pInfo->FileName);
                break;
            case FILE_ACTION_MODIFIED:
                //qDebug() << "modified" << QString::fromStdWString(pInfo->FileName);
                data.action = ActionType::Modify;
                data.filename = QString::fromStdWString(pInfo->FileName);
                break;
            case FILE_ACTION_RENAMED_OLD_NAME:
                //qDebug() << "old name" << QString::fromStdWString(pInfo->FileName);
                data.oldFilename = QString::fromStdWString(pInfo->FileName);
                break;
            case FILE_ACTION_RENAMED_NEW_NAME:
                //qDebug() << "new name" << QString::fromStdWString(pInfo->FileName);
                data.action = ActionType::Rename;
                data.filename = QString::fromStdWString(pInfo->FileName);
                break;
            default:
                qDebug() << "unknown action.";
                break;
            }

            // 发送信号事件
            //pParam->watcher->FileWatch(data);
            //this->FileWatch(data);
            emit OnWatch(data);

            dwOffset += pInfo->NextEntryOffset;
        } while (pInfo->NextEntryOffset != 0);
    }
}


bool hasFile()const
{
    return flags & FILE_NOTIFY_CHANGE_FILE_NAME;
}

bool hasDir()const
{
    return flags & FILE_NOTIFY_CHANGE_DIR_NAME;
}

bool hasAttributes()const
{
    return flags & FILE_NOTIFY_CHANGE_ATTRIBUTES;
}

bool hasSize()const
{
    return flags & FILE_NOTIFY_CHANGE_SIZE;
}

bool hasTimes()const
{
    return flags & (FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_LAST_ACCESS | FILE_NOTIFY_CHANGE_CREATION);
}

bool hasSecurity()const
{
    return flags & FILE_NOTIFY_CHANGE_SECURITY;
}


#endif
