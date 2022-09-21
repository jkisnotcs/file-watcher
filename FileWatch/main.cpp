#include "mainwindow.h"
//#include "vld.h"

#include <QApplication>


#include "database.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_Use96Dpi);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;

    qRegisterMetaType<QVector<int> >("QVector<int>");
    qRegisterMetaType<WatchData>("WatchData");
    //qRegisterMetaType<WatchData>("WatchData&");
    qRegisterMetaType<WatchData>("const WatchData &");
    qRegisterMetaType<WatchData*>("WatchData*");
    qRegisterMetaType<QSharedPointer<WatchData>>("QSharedPointer<WatchData>");  //pointer

    logDB.init();

    /*
    //测试
    for(int i=0; i<10; ++i) {
        LogInfo info(i, "aaa", "bbb");
        logDB.addLog(info);
    }

    QVector<LogInfo> infos = logDB.selectAll();
    for(auto i : infos) {
        qDebug() << i.id << i.time.toString(TIME_FORMAT) << i.action << i.filename << i.oldFilename;
    }

    return 0;
    //*/

    w.show();
    return a.exec();
}
