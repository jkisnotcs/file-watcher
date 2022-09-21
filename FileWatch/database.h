#ifndef USERMANAGER_H
#define USERMANAGER_H
#pragma execution_character_set("utf-8")

#include <QObject>
#include <QDateTime>
#include <QDebug>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/qsqlquerymodel.h>

#include "filewatcher.h"

// 时间格式
#define TIME_FORMAT "yyyy-MM-dd hh:mm:ss"

// 日志信息
struct LogInfo
{
    int       id;            // 唯一ID，由数据库生成
    QDateTime time;          // 时间
    int       action;        // 动作
    QString   filename;      // 文件名
    QString   oldFilename;   // 旧文件名

    LogInfo()
    {
        time = QDateTime().currentDateTime();
    }

    LogInfo(int a, QString fn, QString oldFn)
    {
        time              = QDateTime().currentDateTime();
        this->action      = a;
        this->filename    = fn;
        this->oldFilename = oldFn;
    }
};

// 日志查找标记
enum FindFlags
{
    FindFilename = 1,
    FindTime = 2,
    FindActions = 4,

    // 扩展
    FindFnTime = FindFilename | FindTime,
    FindFnActions = FindFilename | FindActions,
    FindTimeActions = FindTime | FindActions,
    FindAll = FindFilename | FindTime | FindActions,
};

// 日志查询排序方式
enum SortMode
{
    SortNone,               // 无
    SortByTime = 1,         // 根据时间排序
    SortByAction = 2,       // 根据事件排序
    SortByFilename = 3,     // 根据文件名排序
    SortInverse = 0x100,    // 反向排序
};

//
// 日志管理器
//

class LogDatabase
{
private:
    QSqlDatabase database;

public:
    LogDatabase();

    // 执行一条 SQL 语句
    QSqlQuery exec(QString tag, QString sql);

    // 初始化
    int init();

    // 添加一条日志
    bool addLog(const LogInfo& info);

    // 查询所有
    QVector<LogInfo> selectAll();

    // 根据条件查找
    QVector<LogInfo> select(
            QString filename,           // 文件名
            QDateTime startTime,        // 开始时间
            QDateTime endTime,          // 终止时间
            int actions,                // 事件类型
            FindFlags flags,            // 查找参数
            SortMode sortMode           // 排序方式
            );

private:
    // 初始化表
    int initTable();

    // 检查错误，没有错误发生返回 true；发生错误返回 false。
    bool checkError();
};

extern LogDatabase logDB;

#endif   // USERMANAGER_H
