#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>

#include <QFile>
#include <QTextStream>
#include <QDomDocument>

#include "taskdialog.h"
#include "finddialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    iconMain = QIcon(":/res/icon.png");
    this->setWindowIcon(iconMain);
    this->setWindowTitle("文件监控器 ");

    labelMsg = new QLabel(this);
    ui->statusbar->addWidget(labelMsg);

    // 托盘图标
    canExit = false;
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(iconMain);
    this->connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
    trayIcon->show();     // 是否开启托盘图标


    icoRun  = QIcon(":/res/taskRun.png");
    icoStop = QIcon(":/res/taskStop.png");

    // 创建 QStandardItemModel
    m_model = new QStandardItemModel(this);
    ui->listView->setModel(m_model);

    QTableWidget* tab = ui->tableWidget;
    tab->setColumnWidth(0, 150);
    tab->setColumnWidth(1, 100);
    tab->setColumnWidth(2, 400);
    tab->horizontalHeader()->setStretchLastSection(true);

    // 测试
    /*
    for(int i=0; i<10; ++i) {
        TaskInfo info;
        info.path = "aaa";
        for(int j=0; j<3; ++j) {
            info.ignoreFiles.push_back("bbb");
        }
        m_tasks.push_back(new FileWatcher(nullptr, info));
    }
    saveTasks();
    */

    // 加载任务
    loadTasks();
}

MainWindow::~MainWindow()
{
    // 退出前，关闭所有任务
    this->on_btnStopAll_clicked();
    m_tasks.clear();

    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
//    QTableWidget* tab = ui->tableWidget;
//    int w = tab->width();
//    w -= tab->columnWidth(0) + tab->columnWidth(1) + tab->columnCount();
//    tab->setColumnWidth(2, w);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (trayIcon->isVisible()) {
        if (!canExit) {
            trayIcon->showMessage(this->windowTitle(), "最小化到托盘，任务会继续执行。", QSystemTrayIcon::Information, 3000);
            this->hide();   // 最小化
            event->ignore();
        }
        else {
            event->accept();
        }
    }
}

// 托盘图标事件
void MainWindow::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        break;

    case QSystemTrayIcon::DoubleClick:// 显示和隐藏
        if(this->isVisible()) {
            this->hide();
            if (trayIcon->isVisible()) trayIcon->showMessage(
                        this->windowTitle(), "最小化到托盘，任务会继续执行。", QSystemTrayIcon::Information, 3000);
        }
        else {
            this->showNormal();
            //trayIcon->showMessage(this->windowTitle(), "窗口显示。", QSystemTrayIcon::Information, 3000);
        }
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        break;
    }
}

// 接收消息的slot
void MainWindow::OnWatch(const WatchData& data)
{
    QString act;
    QString fn;
    LogInfo info;
    info.action = (int) data.action;
    info.filename = data.filename;
    fn = data.filename;

    switch(data.action) {
    case ActionAdd:
        //qDebug() << "new file" << data.filename;
        act = "新建 ";
        break;
    case ActionRemove:
        //qDebug() << "del file" << data.filename;
        act = "删除 ";
        break;
    case ActionModify:
        //qDebug() << "modified" << data.filename;
        act = "修改 ";
        break;
    case ActionRename:
        //qDebug() << "rename" << data.oldFilename << "->" << data.filename;
        act = "重命名 ";
        info.oldFilename = data.oldFilename;
        fn = fn + " > " + data.oldFilename;
        break;
    default:
        qDebug() << "unknown action.";
        return;
    }

    // 如果窗口没有显示，托盘图标显示信息
    if (!this->isVisible() && trayIcon->isVisible()) {
        trayIcon->showMessage(data.path,
                              QString("%1：\n%2")
                              .arg(act)
                              .arg(fn)
                              , QSystemTrayIcon::Information, 0);
    }

    // 多线程加锁
    m_mutex.lock();

    // 添加日志
    logDB.addLog(info);

    // 输出到界面
    QTableWidget* tab = ui->tableWidget;
    int rowcount = tab->rowCount();
    tab->insertRow(rowcount);

    QTableWidgetItem* item;

    item = new QTableWidgetItem(info.time.toString(TIME_FORMAT));
    item->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
    tab->setItem(rowcount, 0, item);

    item = new QTableWidgetItem(act);
    item->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
    tab->setItem(rowcount, 1, item);

    tab->setItem(rowcount, 2, new QTableWidgetItem(fn));

    // 多线程解锁
    m_mutex.unlock();
}

// 添加一个任务
void MainWindow::addTask(const TaskInfo& info)
{
    // 创建
    FileWatcher* watcher = new FileWatcher(nullptr, info);

    // 链接跨线程信号
    connect(watcher, SIGNAL(OnWatch(const WatchData&)), this, SLOT(OnWatch(const WatchData&)), Qt::DirectConnection);

    m_tasks.append(watcher);

    // 同步界面
    QStandardItem* item = new QStandardItem(icoStop, info.path);
    m_model->appendRow(item);

    // 保存
    saveTasks();

    labelMsg->setText("添加任务成功。");
}

// 移出一个任务
void MainWindow::removeTask(int id)
{
    if (id < 0) {
        return;
    }

    // 停止并删除任务
    FileWatcher* watcher = m_tasks[id];
    if (watcher->isRunning()) {
        watcher->stopWatch();
    }
    m_tasks.remove(id);
    ui->listView->model()->removeRow(id);

    // 保存
    saveTasks();

    labelMsg->setText("任务移出成功。");
}

// 开始任务
void MainWindow::startTask(int id)
{
    if (id < 0) {
        return;
    }

    FileWatcher* watcher = m_tasks[id];
    if (!watcher->isRunning()) {
        watcher->startWatch();

        m_model->setItem(id, new QStandardItem(icoRun, watcher->infomation().path));
        ui->listView->setCurrentIndex(m_model->index(id, 0));

        labelMsg->setText("任务开始……");
    }
}

// 结束任务
void MainWindow::stopTask(int id)
{
    if (id < 0) {
        return;
    }

    FileWatcher* watcher = m_tasks[id];
    if (watcher->isRunning()) {
        watcher->stopWatch();

        m_model->setItem(id, new QStandardItem(icoStop, watcher->infomation().path));
        ui->listView->setCurrentIndex(m_model->index(id, 0));

        labelMsg->setText("任务结束。");
    }
}

// 保存任务列表
void MainWindow::saveTasks()
{
    // 打开文件
    QFile file("tasks.xml");
    if (!file.open(QFile::WriteOnly | QFile::Truncate)) {
        QMessageBox::warning(this, "错误", "文件创建失败。");
        return;
    }

    // 创建 xml
    QDomDocument doc;

    // 初始化 xml 头
    QDomProcessingInstruction ins;
    ins = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(ins);

    // 添加根节点
    QDomElement root = doc.createElement("tasks");
    doc.appendChild(root);

    // 保存所有任务
    for (auto t : m_tasks) {
        // 信息
        TaskInfo info = t->infomation();

        QDomElement task = doc.createElement("task");
        root.appendChild(task);

        QDomElement path = doc.createElement("path");
        path.appendChild(doc.createTextNode(info.path));
        task.appendChild(path);

        QDomElement act = doc.createElement("action");
        act.appendChild(doc.createTextNode(QString::number((int) info.act)));
        task.appendChild(act);

        QDomElement flags = doc.createElement("flags");
        flags.appendChild(doc.createTextNode(QString::number((int) info.flags)));
        task.appendChild(flags);

        // 忽略文件列表
        QDomElement ignoreFiles = doc.createElement("ignoreFiles");
        task.appendChild(ignoreFiles);
        for( auto s : info.ignoreFiles) {
            QDomElement fileNode = doc.createElement("file");
            fileNode.appendChild(doc.createTextNode(s));
            ignoreFiles.appendChild(fileNode);
        }
    }

    // 保存到文件
    QTextStream stm(&file);
    doc.save(stm, 4);   // 缩进 4 格
    file.close();

    labelMsg->setText("任务列表已保存。");
}

// 加载任务列表
void MainWindow::loadTasks()
{
    QDomDocument doc;

    // 停止和清空任务
    this->on_btnStopAll_clicked();
    m_tasks.clear();
    m_model->clear();

    // 打开文件
    QFile file("tasks.xml");
    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, "错误", "文件打开失败。");
        return;
    }

    if (!doc.setContent(&file)) {
        QMessageBox::warning(this, "错误", "XML 解析失败。");
        file.close();
        return;
    }
    file.close();

    // 检查根节点
    QDomElement root = doc.documentElement();
    if (root.isNull() || root.nodeName() != "tasks") {
        QMessageBox::warning(this, "错误", "XML 格式不正确。");
        return;
    }

    // 遍历解析子节点
    QDomNode taskNode = root.firstChildElement("task");
    while (!taskNode.isNull()) {
        //qDebug() << taskNode.nodeName();
        TaskInfo info;

        QDomNode pathNode = taskNode.firstChildElement("path");
        if (!pathNode.isNull()) {
            info.path = pathNode.firstChild().toText().data();
        }

        QDomNode actNode = taskNode.firstChildElement("action");
        if (!actNode.isNull()) {
            info.act = (ActionType) actNode.firstChild().toText().data().toUInt();
        }

        QDomNode flagsNode = taskNode.firstChildElement("flags");
        if (!flagsNode.isNull()) {
            info.flags = (NotifyType) flagsNode.firstChild().toText().data().toUInt();
        }

        // 读取忽略文件列表
        QDomNode ignoreFilesNode = taskNode.firstChildElement("ignoreFiles");
        if(!ignoreFilesNode.isNull()) {
            QDomNode fileNode = ignoreFilesNode.firstChildElement("file");
            while (!fileNode.isNull()) {
                info.ignoreFiles.push_back(fileNode.firstChild().toText().data());
                fileNode = fileNode.nextSiblingElement("file");
            }
        }

        // 添加任务
        if (info.isValid()) {
            this->addTask(info);
        }

        // 下一个节点
        taskNode = taskNode.nextSiblingElement("task");
    }

    labelMsg->setText("任务列表已加载。");
}

// 添加任务
void MainWindow::on_btnAddTask_clicked()
{
    TaskDialog dlg(this);

    if (dlg.showCreate()) {
        this->addTask(dlg.taskInfomation());
    }
    else {
        qDebug() << "添加失败";
    }
}

// 移出任务
void MainWindow::on_btnRemoveTask_clicked()
{
    QModelIndex id = ui->listView->currentIndex();
    //qDebug() << id;
    this->removeTask(id.row());
}

// 设置
void MainWindow::on_btnSetupTask_clicked()
{
    QModelIndex id = ui->listView->currentIndex();
    if (id.row() == -1) {
        return;
    }

    FileWatcher* watcher = m_tasks[id.row()];
    if (watcher->isRunning()) {
        QMessageBox::warning(this, "错误", "停止任务之后再修改。");
        return;
    }

    TaskDialog dlg(this);
    if(dlg.showEdit(watcher)) {//如果修改成功，保存
        saveTasks();
    }
    ui->listView->setCurrentIndex(id);
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    on_btnSetupTask_clicked();
}

// 开始监控
void MainWindow::on_btnStartTask_clicked()
{
    QModelIndex id = ui->listView->currentIndex();
    this->startTask(id.row());
}

// 停止监控
void MainWindow::on_btnStopTask_clicked()
{
    QModelIndex id = ui->listView->currentIndex();
    this->stopTask(id.row());
}

// 全部开始
void MainWindow::on_btnStartAll_clicked()
{
    for (int i = 0; i < m_tasks.size(); ++i) {
        if(!m_tasks[i]->isRunning()) {
            this->startTask(i);
        }
    }
}

// 全部停止
void MainWindow::on_btnStopAll_clicked()
{
    for (int i = 0; i < m_tasks.size(); ++i) {
        if(m_tasks[i]->isRunning()) {
            this->stopTask(i);
        }
    }
}

// 查找
void MainWindow::on_btnFind_clicked()
{
    FindDialog dlg(this);
    dlg.exec();
}

// 清除当前日志
void MainWindow::on_btnClearLog_clicked()
{
    QTableWidget* tab = ui->tableWidget;
    //tab->clear();//error
    tab->model()->removeRows(0, tab->model()->rowCount());
}

// 退出
void MainWindow::on_btnExit_clicked()
{
    canExit = true;
    close();
}

