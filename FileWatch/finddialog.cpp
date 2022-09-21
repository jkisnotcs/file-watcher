#include "finddialog.h"
#include "ui_finddialog.h"

#include "database.h"
#include "filewatcher.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    QTableWidget* tab = ui->tableWidget;
    tab->setColumnWidth(0, 150);
    tab->setColumnWidth(1, 100);
    tab->setColumnWidth(2, 400);
    tab->horizontalHeader()->setStretchLastSection(true);
    //tab->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    QDate date = QDate().currentDate();
    QTime time = QTime().currentTime();

    ui->dateFrom->setDate(date);
    ui->timeFrom->setTime(time);

    ui->dateTo->setDate(date);
    ui->timeTo->setTime(time);
}

FindDialog::~FindDialog()
{
    delete ui;
}


void FindDialog::on_btnFind_clicked()
{
    QString filename;
    QDateTime startTime;
    QDateTime endTime;
    int actions = ActionNone;
    int findFlags = 0;
    int sortMode = 0;

    // 读取界面信息
    if(ui->grpFilename->isChecked()) {
        findFlags |= FindFilename;

        filename = ui->editFilename->text();
    }

    if(ui->grpTime->isChecked()) {
        findFlags |= FindTime;

        startTime = QDateTime(ui->dateFrom->date(), ui->timeFrom->time());
        endTime = QDateTime(ui->dateTo->date(), ui->timeTo->time());
    }

    if(ui->grpActions->isChecked()) {
        findFlags |= FindActions;

        if(ui->chkFileAdd->isChecked()) actions |= ActionAdd;
        if(ui->chkFileRemove->isChecked()) actions |= ActionRemove;
        if(ui->chkFileModify->isChecked()) actions |= ActionModify;
        if(ui->chkFileRename->isChecked()) actions |= ActionRename;
    }

    if(ui->grpSortMode->isChecked()) {
        if(ui->radioSortByTime->isChecked()) {
            sortMode = SortByTime;
        }
        else if(ui->radioSortByAction->isChecked()) {
            sortMode = SortByAction;
        }
        else if(ui->radioSortByName->isChecked()) {
            sortMode = SortByFilename;
        }

        if(sortMode && ui->chkSortInverse->isChecked()) {// 反向排序
            sortMode |= SortInverse;
        }

    }

    QVector<LogInfo> infos = logDB.select(filename, startTime, endTime, actions,
                                          (FindFlags) findFlags, (SortMode) sortMode);

    // 输出到界面
    QTableWidget* tab = ui->tableWidget;
    QString fn;
    QString act;

    // 清空
    tab->model()->removeRows(0, tab->model()->rowCount());

    // 遍历添加到列表
    for (auto info : infos) {
        fn = info.filename;
        switch(info.action) {
        case ActionAdd:
            act = "新建 ";
            break;
        case ActionRemove:
            act = "删除 ";
            break;
        case ActionModify:
            act = "修改 ";
            break;
        case ActionRename:
            act = "重命名 ";
            fn = fn + " > " + info.oldFilename;
            break;
        default:
            qDebug() << "unknown action.";
            return;
        }

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
    }

    ui->grpLogs->setTitle(QString("日志：%0 条记录").arg(tab->rowCount()));

}
