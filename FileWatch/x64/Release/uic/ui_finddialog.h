/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *grpLogs;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *widget;
    QGroupBox *grpActions;
    QVBoxLayout *verticalLayout;
    QCheckBox *chkFileAdd;
    QCheckBox *chkFileRemove;
    QCheckBox *chkFileModify;
    QCheckBox *chkFileRename;
    QGroupBox *grpTime;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QTimeEdit *timeFrom;
    QDateEdit *dateFrom;
    QLabel *label_3;
    QDateEdit *dateTo;
    QTimeEdit *timeTo;
    QGroupBox *grpFilename;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *editFilename;
    QPushButton *btnFind;
    QGroupBox *grpSortMode;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioSortByTime;
    QRadioButton *radioSortByAction;
    QRadioButton *radioSortByName;
    QCheckBox *chkSortInverse;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(800, 600);
        gridLayout = new QGridLayout(FindDialog);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        grpLogs = new QGroupBox(FindDialog);
        grpLogs->setObjectName(QString::fromUtf8("grpLogs"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grpLogs->sizePolicy().hasHeightForWidth());
        grpLogs->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(grpLogs);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 2);
        tableWidget = new QTableWidget(grpLogs);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_2->addWidget(tableWidget);


        gridLayout->addWidget(grpLogs, 0, 1, 1, 1);

        widget = new QWidget(FindDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(200, 0));
        widget->setMaximumSize(QSize(200, 16777215));
        grpActions = new QGroupBox(widget);
        grpActions->setObjectName(QString::fromUtf8("grpActions"));
        grpActions->setGeometry(QRect(0, 230, 201, 115));
        grpActions->setCheckable(true);
        grpActions->setChecked(false);
        verticalLayout = new QVBoxLayout(grpActions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chkFileAdd = new QCheckBox(grpActions);
        chkFileAdd->setObjectName(QString::fromUtf8("chkFileAdd"));
        chkFileAdd->setChecked(true);

        verticalLayout->addWidget(chkFileAdd);

        chkFileRemove = new QCheckBox(grpActions);
        chkFileRemove->setObjectName(QString::fromUtf8("chkFileRemove"));
        chkFileRemove->setChecked(true);

        verticalLayout->addWidget(chkFileRemove);

        chkFileModify = new QCheckBox(grpActions);
        chkFileModify->setObjectName(QString::fromUtf8("chkFileModify"));
        chkFileModify->setChecked(true);

        verticalLayout->addWidget(chkFileModify);

        chkFileRename = new QCheckBox(grpActions);
        chkFileRename->setObjectName(QString::fromUtf8("chkFileRename"));
        chkFileRename->setChecked(true);

        verticalLayout->addWidget(chkFileRename);

        grpTime = new QGroupBox(widget);
        grpTime->setObjectName(QString::fromUtf8("grpTime"));
        grpTime->setGeometry(QRect(0, 70, 201, 151));
        grpTime->setCheckable(true);
        grpTime->setChecked(false);
        gridLayout_3 = new QGridLayout(grpTime);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(grpTime);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        timeFrom = new QTimeEdit(grpTime);
        timeFrom->setObjectName(QString::fromUtf8("timeFrom"));

        gridLayout_3->addWidget(timeFrom, 2, 1, 1, 1);

        dateFrom = new QDateEdit(grpTime);
        dateFrom->setObjectName(QString::fromUtf8("dateFrom"));

        gridLayout_3->addWidget(dateFrom, 1, 1, 1, 1);

        label_3 = new QLabel(grpTime);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        dateTo = new QDateEdit(grpTime);
        dateTo->setObjectName(QString::fromUtf8("dateTo"));

        gridLayout_3->addWidget(dateTo, 3, 1, 1, 1);

        timeTo = new QTimeEdit(grpTime);
        timeTo->setObjectName(QString::fromUtf8("timeTo"));

        gridLayout_3->addWidget(timeTo, 4, 1, 1, 1);

        grpFilename = new QGroupBox(widget);
        grpFilename->setObjectName(QString::fromUtf8("grpFilename"));
        grpFilename->setGeometry(QRect(0, 10, 207, 53));
        grpFilename->setCheckable(true);
        grpFilename->setChecked(false);
        gridLayout_4 = new QGridLayout(grpFilename);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(grpFilename);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        editFilename = new QLineEdit(grpFilename);
        editFilename->setObjectName(QString::fromUtf8("editFilename"));

        gridLayout_4->addWidget(editFilename, 0, 1, 1, 1);

        btnFind = new QPushButton(widget);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));
        btnFind->setGeometry(QRect(120, 480, 75, 23));
        grpSortMode = new QGroupBox(widget);
        grpSortMode->setObjectName(QString::fromUtf8("grpSortMode"));
        grpSortMode->setGeometry(QRect(0, 350, 201, 121));
        grpSortMode->setCheckable(true);
        grpSortMode->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(grpSortMode);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioSortByTime = new QRadioButton(grpSortMode);
        radioSortByTime->setObjectName(QString::fromUtf8("radioSortByTime"));
        radioSortByTime->setChecked(true);

        verticalLayout_3->addWidget(radioSortByTime);

        radioSortByAction = new QRadioButton(grpSortMode);
        radioSortByAction->setObjectName(QString::fromUtf8("radioSortByAction"));

        verticalLayout_3->addWidget(radioSortByAction);

        radioSortByName = new QRadioButton(grpSortMode);
        radioSortByName->setObjectName(QString::fromUtf8("radioSortByName"));

        verticalLayout_3->addWidget(radioSortByName);

        chkSortInverse = new QCheckBox(grpSortMode);
        chkSortInverse->setObjectName(QString::fromUtf8("chkSortInverse"));

        verticalLayout_3->addWidget(chkSortInverse);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        grpLogs->setTitle(QCoreApplication::translate("FindDialog", "\346\227\245\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FindDialog", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FindDialog", "\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FindDialog", "\346\226\207\344\273\266", nullptr));
        grpActions->setTitle(QCoreApplication::translate("FindDialog", "\344\272\213\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        chkFileAdd->setText(QCoreApplication::translate("FindDialog", "\346\226\260\345\273\272", nullptr));
        chkFileRemove->setText(QCoreApplication::translate("FindDialog", "\345\210\240\351\231\244", nullptr));
        chkFileModify->setText(QCoreApplication::translate("FindDialog", "\346\233\264\346\224\271", nullptr));
        chkFileRename->setText(QCoreApplication::translate("FindDialog", "\351\207\215\345\221\275\345\220\215", nullptr));
        grpTime->setTitle(QCoreApplication::translate("FindDialog", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FindDialog", "\344\273\216\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FindDialog", "\345\210\260\357\274\232", nullptr));
        grpFilename->setTitle(QCoreApplication::translate("FindDialog", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("FindDialog", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        btnFind->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        grpSortMode->setTitle(QCoreApplication::translate("FindDialog", "\346\216\222\345\272\217\346\226\271\345\274\217", nullptr));
        radioSortByTime->setText(QCoreApplication::translate("FindDialog", "\346\227\266\351\227\264", nullptr));
        radioSortByAction->setText(QCoreApplication::translate("FindDialog", "\344\272\213\344\273\266", nullptr));
        radioSortByName->setText(QCoreApplication::translate("FindDialog", "\346\226\207\344\273\266\345\220\215", nullptr));
        chkSortInverse->setText(QCoreApplication::translate("FindDialog", "\345\217\215\345\220\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
