#ifndef TASKDIALOG_H
#define TASKDIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "filewatcher.h"

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();

    // 显示创建任务
    bool showCreate();

    // 显示修改任务
    bool showEdit(FileWatcher* watcher);

    // 返回信息
    TaskInfo taskInfomation()const;

private slots:
    void on_btnDir_clicked();

    void on_buttonBox_accepted();

private:
    Ui::TaskDialog *ui;

    FileWatcher* m_watcher;     // 任务指针，如果是创建模式，则不使用
    TaskInfo m_info;            // 任务信息

    void accept() override;
};

#endif // TASKDIALOG_H
