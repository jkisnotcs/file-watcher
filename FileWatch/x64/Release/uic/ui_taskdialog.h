/********************************************************************************
** Form generated from reading UI file 'taskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *editDir;
    QLabel *label;
    QPushButton *btnDir;
    QLabel *label_3;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QCheckBox *chkFileRename;
    QCheckBox *chkFileRemove;
    QCheckBox *chkFileModify;
    QCheckBox *chkFileAdd;
    QGroupBox *groupBox_2;
    QCheckBox *chkNotifyTimes;
    QCheckBox *chkNotifyDir;
    QCheckBox *chkNotifyAttribute;
    QCheckBox *chkNotifySize;
    QCheckBox *chkNotifyFile;
    QCheckBox *chkNotifySecurity;

    void setupUi(QDialog *TaskDialog)
    {
        if (TaskDialog->objectName().isEmpty())
            TaskDialog->setObjectName(QString::fromUtf8("TaskDialog"));
        TaskDialog->resize(640, 380);
        buttonBox = new QDialogButtonBox(TaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(440, 340, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editDir = new QLineEdit(TaskDialog);
        editDir->setObjectName(QString::fromUtf8("editDir"));
        editDir->setGeometry(QRect(10, 30, 561, 20));
        label = new QLabel(TaskDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 54, 12));
        btnDir = new QPushButton(TaskDialog);
        btnDir->setObjectName(QString::fromUtf8("btnDir"));
        btnDir->setGeometry(QRect(580, 30, 41, 23));
        label_3 = new QLabel(TaskDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 180, 511, 16));
        listWidget = new QListWidget(TaskDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 200, 621, 131));
        groupBox = new QGroupBox(TaskDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 611, 51));
        chkFileRename = new QCheckBox(groupBox);
        chkFileRename->setObjectName(QString::fromUtf8("chkFileRename"));
        chkFileRename->setGeometry(QRect(250, 20, 83, 16));
        chkFileRemove = new QCheckBox(groupBox);
        chkFileRemove->setObjectName(QString::fromUtf8("chkFileRemove"));
        chkFileRemove->setGeometry(QRect(90, 20, 71, 16));
        chkFileModify = new QCheckBox(groupBox);
        chkFileModify->setObjectName(QString::fromUtf8("chkFileModify"));
        chkFileModify->setGeometry(QRect(170, 20, 71, 16));
        chkFileAdd = new QCheckBox(groupBox);
        chkFileAdd->setObjectName(QString::fromUtf8("chkFileAdd"));
        chkFileAdd->setGeometry(QRect(10, 20, 71, 16));
        groupBox_2 = new QGroupBox(TaskDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 611, 51));
        chkNotifyTimes = new QCheckBox(groupBox_2);
        chkNotifyTimes->setObjectName(QString::fromUtf8("chkNotifyTimes"));
        chkNotifyTimes->setGeometry(QRect(340, 20, 71, 16));
        chkNotifyDir = new QCheckBox(groupBox_2);
        chkNotifyDir->setObjectName(QString::fromUtf8("chkNotifyDir"));
        chkNotifyDir->setGeometry(QRect(90, 20, 71, 16));
        chkNotifyAttribute = new QCheckBox(groupBox_2);
        chkNotifyAttribute->setObjectName(QString::fromUtf8("chkNotifyAttribute"));
        chkNotifyAttribute->setGeometry(QRect(170, 20, 71, 16));
        chkNotifySize = new QCheckBox(groupBox_2);
        chkNotifySize->setObjectName(QString::fromUtf8("chkNotifySize"));
        chkNotifySize->setGeometry(QRect(250, 20, 71, 16));
        chkNotifyFile = new QCheckBox(groupBox_2);
        chkNotifyFile->setObjectName(QString::fromUtf8("chkNotifyFile"));
        chkNotifyFile->setGeometry(QRect(10, 20, 71, 16));
        chkNotifySecurity = new QCheckBox(groupBox_2);
        chkNotifySecurity->setObjectName(QString::fromUtf8("chkNotifySecurity"));
        chkNotifySecurity->setGeometry(QRect(430, 20, 71, 16));

        retranslateUi(TaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TaskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TaskDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskDialog)
    {
        TaskDialog->setWindowTitle(QCoreApplication::translate("TaskDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TaskDialog", "\347\233\256\345\275\225\357\274\232", nullptr));
        btnDir->setText(QCoreApplication::translate("TaskDialog", "...", nullptr));
        label_3->setText(QCoreApplication::translate("TaskDialog", "\346\216\222\351\231\244\351\200\211\351\241\271\357\274\232\357\274\210\346\216\222\351\231\244\346\214\207\345\256\232\346\226\207\344\273\266\347\233\221\346\216\247\357\274\211", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TaskDialog", "\344\272\213\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        chkFileRename->setText(QCoreApplication::translate("TaskDialog", "\351\207\215\345\221\275\345\220\215", nullptr));
        chkFileRemove->setText(QCoreApplication::translate("TaskDialog", "\345\210\240\351\231\244", nullptr));
        chkFileModify->setText(QCoreApplication::translate("TaskDialog", "\346\233\264\346\224\271", nullptr));
        chkFileAdd->setText(QCoreApplication::translate("TaskDialog", "\346\226\260\345\273\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("TaskDialog", "\351\200\232\347\237\245\347\261\273\345\236\213\357\274\232", nullptr));
        chkNotifyTimes->setText(QCoreApplication::translate("TaskDialog", "\346\227\266\351\227\264\346\233\264\346\224\271", nullptr));
        chkNotifyDir->setText(QCoreApplication::translate("TaskDialog", "\347\233\256\345\275\225", nullptr));
        chkNotifyAttribute->setText(QCoreApplication::translate("TaskDialog", "\345\261\236\346\200\247\346\233\264\346\224\271", nullptr));
        chkNotifySize->setText(QCoreApplication::translate("TaskDialog", "\345\244\247\345\260\217\346\233\264\346\224\271", nullptr));
        chkNotifyFile->setText(QCoreApplication::translate("TaskDialog", "\346\226\207\344\273\266", nullptr));
        chkNotifySecurity->setText(QCoreApplication::translate("TaskDialog", "\346\235\203\351\231\220\346\233\264\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDialog: public Ui_TaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
