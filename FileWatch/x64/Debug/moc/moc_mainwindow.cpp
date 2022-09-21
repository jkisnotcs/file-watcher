/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "OnWatch"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "WatchData"
QT_MOC_LITERAL(4, 30, 4), // "data"
QT_MOC_LITERAL(5, 35, 21), // "on_btnAddTask_clicked"
QT_MOC_LITERAL(6, 57, 24), // "on_btnRemoveTask_clicked"
QT_MOC_LITERAL(7, 82, 23), // "on_btnStartTask_clicked"
QT_MOC_LITERAL(8, 106, 22), // "on_btnStopTask_clicked"
QT_MOC_LITERAL(9, 129, 23), // "on_btnSetupTask_clicked"
QT_MOC_LITERAL(10, 153, 18), // "on_btnFind_clicked"
QT_MOC_LITERAL(11, 172, 22), // "on_btnStartAll_clicked"
QT_MOC_LITERAL(12, 195, 21), // "on_btnStopAll_clicked"
QT_MOC_LITERAL(13, 217, 18), // "on_btnExit_clicked"
QT_MOC_LITERAL(14, 236, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(15, 262, 11), // "QModelIndex"
QT_MOC_LITERAL(16, 274, 5), // "index"
QT_MOC_LITERAL(17, 280, 22), // "on_btnClearLog_clicked"
QT_MOC_LITERAL(18, 303, 11), // "onActivated"
QT_MOC_LITERAL(19, 315, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(20, 349, 6) // "reason"

    },
    "MainWindow\0OnWatch\0\0WatchData\0data\0"
    "on_btnAddTask_clicked\0on_btnRemoveTask_clicked\0"
    "on_btnStartTask_clicked\0on_btnStopTask_clicked\0"
    "on_btnSetupTask_clicked\0on_btnFind_clicked\0"
    "on_btnStartAll_clicked\0on_btnStopAll_clicked\0"
    "on_btnExit_clicked\0on_listView_doubleClicked\0"
    "QModelIndex\0index\0on_btnClearLog_clicked\0"
    "onActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,
      17,    0,   94,    2, 0x08 /* Private */,
      18,    1,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnWatch((*reinterpret_cast< const WatchData(*)>(_a[1]))); break;
        case 1: _t->on_btnAddTask_clicked(); break;
        case 2: _t->on_btnRemoveTask_clicked(); break;
        case 3: _t->on_btnStartTask_clicked(); break;
        case 4: _t->on_btnStopTask_clicked(); break;
        case 5: _t->on_btnSetupTask_clicked(); break;
        case 6: _t->on_btnFind_clicked(); break;
        case 7: _t->on_btnStartAll_clicked(); break;
        case 8: _t->on_btnStopAll_clicked(); break;
        case 9: _t->on_btnExit_clicked(); break;
        case 10: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_btnClearLog_clicked(); break;
        case 12: _t->onActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WatchData >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
