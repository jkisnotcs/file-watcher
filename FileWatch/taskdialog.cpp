#include "taskdialog.h"
#include "ui_taskdialog.h"

#include <QFileDialog>
#include <QDebug>

#include <QStringListModel>

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    this->setFixedSize(640, 380);
    m_watcher = nullptr;

}

TaskDialog::~TaskDialog()
{
    delete ui;
}

// 返回信息
TaskInfo TaskDialog::taskInfomation()const
{
    return m_info;
}

void TaskDialog::on_btnDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择文件夹 ", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty()) {
        ui->editDir->setText(dir);
    }
}

// 显示创建任务
bool TaskDialog::showCreate()
{
    this->setWindowTitle("创建任务 ");
    m_watcher = nullptr;

    // 初始化界面
    ui->chkFileAdd->setChecked(true);
    ui->chkFileRemove->setChecked(true);
    ui->chkFileModify->setChecked(true);
    ui->chkFileRename->setChecked(true);

    ui->chkNotifyFile->setChecked(true);
    ui->chkNotifyDir->setChecked(true);
    ui->chkNotifyAttribute->setChecked(true);
    ui->chkNotifySize->setChecked(true);
    ui->chkNotifyTimes->setChecked(true);
    ui->chkNotifySecurity->setChecked(true);

    if (this->exec() == QDialog::Accepted) {
        return true;
    }
    else {
        return false;
    }
}

// 显示修改任务
bool TaskDialog::showEdit(FileWatcher* watcher)
{
    this->setWindowTitle("修改任务 ");
    m_watcher = watcher;
    m_info = watcher->infomation();

    // 初始化界面，读取配置
    ui->editDir->setText(m_info.path);

    ui->chkFileAdd->setChecked(m_info.act & ActionAdd);
    ui->chkFileRemove->setChecked(m_info.act & ActionRemove);
    ui->chkFileModify->setChecked(m_info.act & ActionModify);
    ui->chkFileRename->setChecked(m_info.act & ActionRename);

    ui->chkNotifyFile->setChecked(m_info.flags & NotifyFile);
    ui->chkNotifyDir->setChecked(m_info.flags & NotifyDir);
    ui->chkNotifyAttribute->setChecked(m_info.flags & NotifyAttribute);
    ui->chkNotifySize->setChecked(m_info.flags & NotifySize);
    ui->chkNotifyTimes->setChecked(m_info.flags & NotifyTimes);
    ui->chkNotifySecurity->setChecked(m_info.flags & NotifySecurity);

    ui->listWidget->clear();
    ui->listWidget->addItems(m_info.ignoreFiles);

    if (this->exec() == QDialog::Accepted) {
        return true;
    }
    else {
        return false;
    }
}

// 点击确定按钮
void TaskDialog::on_buttonBox_accepted()
{
    m_info.path = ui->editDir->text();

    int act = 0;
    if(ui->chkFileAdd->isChecked()) act |= ActionAdd;
    if(ui->chkFileRemove->isChecked()) act |= ActionRemove;
    if(ui->chkFileModify->isChecked()) act |= ActionModify;
    if(ui->chkFileRename->isChecked()) act |= ActionRename;
    m_info.act = act;

    int  flags = 0;
    if(ui->chkNotifyFile->isChecked()) flags |= NotifyFile;
    if(ui->chkNotifyDir->isChecked()) flags |= NotifyDir;
    if(ui->chkNotifyAttribute->isChecked()) flags |= NotifyAttribute;
    if(ui->chkNotifySize->isChecked()) flags |= NotifySize;
    if(ui->chkNotifyTimes->isChecked()) flags |= NotifyTimes;
    if(ui->chkNotifySecurity->isChecked()) flags |= NotifySecurity;
    m_info.flags = flags;

    QStringListModel* model = qobject_cast<QStringListModel*>(ui->listWidget->model());
    if(model) {
        m_info.ignoreFiles = model->stringList();
    }

    //qDebug() << act << flags;

    // 编辑状态，设置任务信息
    if (m_watcher) {
        //if(m_info.isValid()) {//如果有效，才写回去
            m_watcher->setInfomation(m_info);
        //}
    }
}


#include <QToolTip>

void TaskDialog::accept()
{
    // 检查设置
    if (ui->editDir->text().length() == 0) {
        ui->editDir->setFocus();
        QPoint pos = ui->editDir->mapToGlobal(QPoint(0, ui->editDir->height() / 2));
        QToolTip::showText(pos, "目录不能为空。", ui->editDir);
    }
    else {
        this->setResult(QDialog::Accepted);
        this->hide();
    }
}
