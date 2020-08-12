/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[23];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 9), // "connected"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "disconnected"
QT_MOC_LITERAL(4, 31, 19), // "readyReadQTcpSocket"
QT_MOC_LITERAL(5, 51, 19), // "readyReadQUdpSocket"
QT_MOC_LITERAL(6, 71, 9), // "isInRange"
QT_MOC_LITERAL(7, 81, 3), // "seq"
QT_MOC_LITERAL(8, 85, 8), // "sendFile"
QT_MOC_LITERAL(9, 94, 16), // "sendFileResponse"
QT_MOC_LITERAL(10, 111, 16), // "QAbstractButton*"
QT_MOC_LITERAL(11, 128, 6), // "resend"
QT_MOC_LITERAL(12, 135, 26), // "on_loginPushButton_clicked"
QT_MOC_LITERAL(13, 162, 41), // "on_interfacesComboBox_current..."
QT_MOC_LITERAL(14, 204, 5), // "index"
QT_MOC_LITERAL(15, 210, 32), // "on_onlineUsersListWidget_clicked"
QT_MOC_LITERAL(16, 243, 27), // "on_logoutPushButton_clicked"
QT_MOC_LITERAL(17, 271, 25), // "on_sendPushButton_clicked"
QT_MOC_LITERAL(18, 297, 28), // "on_msgLineEdit_returnPressed"
QT_MOC_LITERAL(19, 326, 26), // "on_sendFile_button_clicked"
QT_MOC_LITERAL(20, 353, 8), // "rdt_send"
QT_MOC_LITERAL(21, 362, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(22, 386, 4) // "arg1"

    },
    "Client\0connected\0\0disconnected\0"
    "readyReadQTcpSocket\0readyReadQUdpSocket\0"
    "isInRange\0seq\0sendFile\0sendFileResponse\0"
    "QAbstractButton*\0resend\0"
    "on_loginPushButton_clicked\0"
    "on_interfacesComboBox_currentIndexChanged\0"
    "index\0on_onlineUsersListWidget_clicked\0"
    "on_logoutPushButton_clicked\0"
    "on_sendPushButton_clicked\0"
    "on_msgLineEdit_returnPressed\0"
    "on_sendFile_button_clicked\0rdt_send\0"
    "on_lineEdit_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    1,  103,    2, 0x0a /* Public */,
       8,    0,  106,    2, 0x0a /* Public */,
       9,    1,  107,    2, 0x08 /* Private */,
      11,    0,  110,    2, 0x08 /* Private */,
      12,    0,  111,    2, 0x08 /* Private */,
      13,    1,  112,    2, 0x08 /* Private */,
      15,    1,  115,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->readyReadQTcpSocket(); break;
        case 3: _t->readyReadQUdpSocket(); break;
        case 4: { bool _r = _t->isInRange((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->sendFile(); break;
        case 6: _t->sendFileResponse((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 7: _t->resend(); break;
        case 8: _t->on_loginPushButton_clicked(); break;
        case 9: _t->on_interfacesComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_onlineUsersListWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_logoutPushButton_clicked(); break;
        case 12: _t->on_sendPushButton_clicked(); break;
        case 13: _t->on_msgLineEdit_returnPressed(); break;
        case 14: _t->on_sendFile_button_clicked(); break;
        case 15: _t->rdt_send(); break;
        case 16: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    return QWidget::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
