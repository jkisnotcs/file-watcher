/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *widgetTasks;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAddTask;
    QPushButton *btnRemoveTask;
    QPushButton *btnSetupTask;
    QWidget *widget_2;
    QPushButton *btnStartTask;
    QPushButton *btnStopTask;
    QPushButton *btnStartAll;
    QPushButton *btnStopAll;
    QWidget *widget_3;
    QPushButton *btnFind;
    QPushButton *btnClearLog;
    QWidget *widget_4;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 576);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 2);
        tableWidget = new QTableWidget(groupBox);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_2->addWidget(tableWidget);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        widgetTasks = new QWidget(centralwidget);
        widgetTasks->setObjectName(QString::fromUtf8("widgetTasks"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTasks->sizePolicy().hasHeightForWidth());
        widgetTasks->setSizePolicy(sizePolicy1);
        widgetTasks->setMinimumSize(QSize(200, 0));
        widgetTasks->setMaximumSize(QSize(320, 16777215));
        verticalLayout = new QVBoxLayout(widgetTasks);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        listView = new QListView(widgetTasks);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);


        gridLayout->addWidget(widgetTasks, 1, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        btnAddTask = new QPushButton(widget);
        btnAddTask->setObjectName(QString::fromUtf8("btnAddTask"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/ic_add_circle_outline_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddTask->setIcon(icon);
        btnAddTask->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnAddTask);

        btnRemoveTask = new QPushButton(widget);
        btnRemoveTask->setObjectName(QString::fromUtf8("btnRemoveTask"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/ic_remove_circle_outline_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveTask->setIcon(icon1);
        btnRemoveTask->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnRemoveTask);

        btnSetupTask = new QPushButton(widget);
        btnSetupTask->setObjectName(QString::fromUtf8("btnSetupTask"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/ic_build_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetupTask->setIcon(icon2);
        btnSetupTask->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnSetupTask);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout_2->addWidget(widget_2);

        btnStartTask = new QPushButton(widget);
        btnStartTask->setObjectName(QString::fromUtf8("btnStartTask"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/ic_play_circle_outline_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStartTask->setIcon(icon3);
        btnStartTask->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnStartTask);

        btnStopTask = new QPushButton(widget);
        btnStopTask->setObjectName(QString::fromUtf8("btnStopTask"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/ic_pause_circle_outline_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStopTask->setIcon(icon4);
        btnStopTask->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnStopTask);

        btnStartAll = new QPushButton(widget);
        btnStartAll->setObjectName(QString::fromUtf8("btnStartAll"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/ic_play_arrow_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStartAll->setIcon(icon5);
        btnStartAll->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnStartAll);

        btnStopAll = new QPushButton(widget);
        btnStopAll->setObjectName(QString::fromUtf8("btnStopAll"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/ic_pause_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStopAll->setIcon(icon6);
        btnStopAll->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnStopAll);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        horizontalLayout_2->addWidget(widget_3);

        btnFind = new QPushButton(widget);
        btnFind->setObjectName(QString::fromUtf8("btnFind"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/ic_search_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFind->setIcon(icon7);
        btnFind->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnFind);

        btnClearLog = new QPushButton(widget);
        btnClearLog->setObjectName(QString::fromUtf8("btnClearLog"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/ic_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearLog->setIcon(icon8);
        btnClearLog->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnClearLog);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        horizontalLayout_2->addWidget(widget_4);

        btnExit = new QPushButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/ic_exit_to_app_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon9);
        btnExit->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(btnExit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addWidget(widget, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\227\245\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        btnAddTask->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAddTask->setText(QString());
#if QT_CONFIG(tooltip)
        btnRemoveTask->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRemoveTask->setText(QString());
#if QT_CONFIG(tooltip)
        btnSetupTask->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSetupTask->setText(QString());
#if QT_CONFIG(tooltip)
        btnStartTask->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\346\216\247", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStartTask->setText(QString());
#if QT_CONFIG(tooltip)
        btnStopTask->setToolTip(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\346\216\247", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStopTask->setText(QString());
        btnStartAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\345\274\200\345\247\213", nullptr));
        btnStopAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\345\201\234\346\255\242", nullptr));
#if QT_CONFIG(tooltip)
        btnFind->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
#endif // QT_CONFIG(tooltip)
        btnFind->setText(QString());
#if QT_CONFIG(tooltip)
        btnClearLog->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\220\206\347\225\214\351\235\242\346\227\245\345\277\227", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClearLog->setText(QString());
#if QT_CONFIG(tooltip)
        btnExit->setToolTip(QCoreApplication::translate("MainWindow", "\346\210\221\346\230\257\347\234\237\351\200\200\345\207\272\342\200\246\342\200\246", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
