#include "database.h"

LogDatabase logDB;

const QString databaseName = "log.db";
const QString tableName    = "logTable";

/*
QDate dateEdit=ui->dateEdit->date();
QString date=dateEdit.toString("yyyy-MM-dd");
QSqlQuery.exec(QString("数据库查询语句").arg(date));
*/

LogDatabase::LogDatabase() { }

// 执行一条 SQL 语句
QSqlQuery LogDatabase::exec(QString tag, QString sql)
{
    qDebug() << QTime().currentTime().toString() << "sql>" << sql;

    if (!database.isOpen()) {
        qDebug() << tag << "数据库未打开。";
        return QSqlQuery();
    }

    QSqlQuery sqlQuery = QSqlQuery(database);
    if (!sqlQuery.prepare(sql)) {
        qDebug() << tag << sqlQuery.lastError();
        return QSqlQuery();
    }

    if (!sqlQuery.exec()) {
        qDebug() << tag << sqlQuery.lastError();
        return QSqlQuery();
    }

    return sqlQuery;
}

// 检查错误，没有错误发生返回 true；发生错误返回 false。
bool LogDatabase::checkError()
{
    if (!database.isOpen()) {
        qDebug() << "数据库未打开。";
        return false;
    }

    if (!database.tables().contains(tableName)) {
        qDebug() << "表格不存在。";
        return false;
    }

    return true;
}

// 初始化
int LogDatabase::init()
{
//    if (QSqlDatabase::contains("qt_sql_default_connection")) {
//        database = QSqlDatabase::database("qt_sql_default_connection");
//    }
//    else {
        database = QSqlDatabase::addDatabase("QSQLITE");   // 数据库种类
        database.setDatabaseName(databaseName);            // 数据库名称
        database.setUserName("root");                      // 账号
        database.setPassword("123456");                    // 密码

        if (!database.open()) {
            qDebug() << database.lastError();
            return -1;
        }

        // 初始化表格
        this->initTable();
//    }

    return 0;
}

// 初始化表
int LogDatabase::initTable()
{
    if (!database.isOpen()) {
        qDebug() << "数据库未打开。";
        return -1;
    }

    // 这里用了一个主键 id，由数据库自动累加。
    QString sql = QString("create table if not exists %1 ("
                          "id integer primary key,"
                          "tm datatime,"
                          "act integer,"
                          "fn text(256),"
                          "oldFn text(256))")
            .arg(tableName);

    this->exec("initTable()", sql);

    return 0;
}

// 添加一条日志
bool LogDatabase::addLog(const LogInfo& info)
{
    if (!checkError()) {
        return false;
    }

    QString cmd = QString("insert into %1 (tm,act,fn,oldFn) values('%2','%3','%4','%5')")
                      .arg(tableName)
                      .arg(info.time.toString(TIME_FORMAT))
                      .arg(info.action)
                      .arg(info.filename)
                      .arg(info.oldFilename);

    this->exec("addLog()", cmd);

    return true;
}

// 查询所有
QVector<LogInfo> LogDatabase::selectAll()
{
    QVector<LogInfo> infos;

    if (!checkError()) {
        return infos;
    }

    QString sql = QString("select * from %1").arg(tableName);

    // 执行查询操作，保存到列表
    QSqlQuery sqlQuery = this->exec("selectAll()", sql);
    while (sqlQuery.next()) {
        LogInfo info;
        info.id          = sqlQuery.value(0).toInt();
        info.time        = sqlQuery.value(1).toDateTime();
        info.action      = sqlQuery.value(2).toInt();
        info.filename    = sqlQuery.value(3).toString();
        info.oldFilename = sqlQuery.value(4).toString();
        infos.push_back(info);
    }

    return infos;
}

// 根据条件查找
QVector<LogInfo> LogDatabase::select(
    QString filename,
    QDateTime startTime,
    QDateTime endTime,
    int actions,
    FindFlags flags, SortMode sortMode)
{
    QVector<LogInfo> infos;

    if (!checkError()) {
        return infos;
    }

    // 时间格式化成字符串
    QString tmStart = startTime.toString(TIME_FORMAT);
    QString tmEnd = endTime.toString(TIME_FORMAT);

    QString sql;    // sql 语句

    // 根据不同参数标签，生成不同的 sql 语句
    switch(flags) {
    case FindFilename:
        sql = QString("select * from %1 where (fn like '%%2%' or oldFn like '%%2%')").arg(tableName).arg(filename);
        break;
    case FindTime:
        sql = QString("select * from %1 where (tm >= '%2' and tm <= '%3')").arg(tableName).arg(tmStart).arg(tmEnd);
        break;
    case FindFnTime:// 文件名和时间一起查找
        sql = QString("select * from %1 where (fn like '%%2%' or oldFn like '%%2%') and (tm >= '%3' and tm <= '%4')")
                .arg(tableName)
                .arg(filename)
                .arg(tmStart)
                .arg(tmEnd);
        break;
    case FindActions:
        sql = QString("select * from %1 where (act & '%2' != 0)").arg(tableName).arg(actions);
        break;
    case FindFnActions:
        sql = QString("select * from %1 where (fn like '%%2%' or oldFn like '%%2%') and (act & '%3' != 0)")
                .arg(tableName)
                .arg(filename)
                .arg(actions);
        break;
    case FindTimeActions:
        sql = QString("select * from %1 where (tm >= '%2' and tm <= '%3') and (act & '%4' != 0)")
                .arg(tableName)
                .arg(tmStart)
                .arg(tmEnd)
                .arg(actions);
        break;
    case FindAll:
        sql = QString("select * from %1 where (fn like '%%2%' or oldFn like '%%2%') and (tm >= '%3' and tm <= '%4') and (act & '%5' != 0)")
                .arg(tableName)
                .arg(filename)
                .arg(tmStart)
                .arg(tmEnd)
                .arg(actions);
        break;
    default:
        return infos;
    }

    // 排序语句
    if (sortMode != SortNone) {
        int n = sortMode & 0xFF;
        bool inv = (sortMode & SortInverse) == SortInverse;
        switch(n) {
        case SortByTime:
            sql.append(" order by tm");
            if(inv)sql.append(" desc");
            break;
        case SortByAction:
            sql.append(" order by act");
            if(inv)sql.append(" desc");
            break;
        case SortByFilename:
            sql.append(" order by fn");
            if(inv)sql.append(" desc");
            break;
        default:
            break;
        }
    }

    // 执行查询操作，保存到列表
    QSqlQuery sqlQuery = this->exec("select(...)", sql);
    while (sqlQuery.next()) {
        LogInfo info;
        info.id          = sqlQuery.value(0).toInt();
        info.time        = sqlQuery.value(1).toDateTime();
        info.action      = sqlQuery.value(2).toInt();
        info.filename    = sqlQuery.value(3).toString();
        info.oldFilename = sqlQuery.value(4).toString();
        infos.push_back(info);
    }

    return infos;
}


