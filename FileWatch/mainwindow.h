#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMutex>

#include <QSystemTrayIcon>      // 托盘图标

#include "filewatcher.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




protected:

    //void timerEvent(QTimerEvent *event)override;
    void resizeEvent(QResizeEvent *event)override;
    void closeEvent(QCloseEvent *event)override;

public slots:
    void OnWatch(const WatchData& data);

private slots:
    void on_btnAddTask_clicked();

    void on_btnRemoveTask_clicked();

    void on_btnStartTask_clicked();

    void on_btnStopTask_clicked();

    void on_btnSetupTask_clicked();

    void on_btnFind_clicked();

    void on_btnStartAll_clicked();

    void on_btnStopAll_clicked();

    void on_btnExit_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_btnClearLog_clicked();

    // 托盘图标事件
    void onActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    QLabel* labelMsg;

    QIcon iconMain;
    QSystemTrayIcon* trayIcon;      // 图盘图标
    bool canExit;                   // 标记是否退出，退出按钮点击的时候，完全退出

    QVector<FileWatcher*> m_tasks;  // 任务列表

    QIcon icoRun;
    QIcon icoStop;

    QStandardItemModel* m_model;    // listView 列表项目

    QMutex m_mutex; // 加锁

    // 添加一个任务
    void addTask(const TaskInfo& info);

    // 移出一个任务
    void removeTask(int id);

    // 开始任务
    void startTask(int id);

    // 结束任务
    void stopTask(int id);

    // 保存任务列表
    void saveTasks();

    // 加载任务列表
    void loadTasks();

};
#endif // MAINWINDOW_H
