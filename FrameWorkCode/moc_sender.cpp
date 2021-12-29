/****************************************************************************
** Meta object code from reading C++ file 'sender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SimpleMail/sender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleMail__Sender_t {
    QByteArrayData data[33];
    char stringdata0[466];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleMail__Sender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleMail__Sender_t qt_meta_stringdata_SimpleMail__Sender = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SimpleMail::Sender"
QT_MOC_LITERAL(1, 19, 9), // "smtpError"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "SmtpError"
QT_MOC_LITERAL(4, 40, 1), // "e"
QT_MOC_LITERAL(5, 42, 9), // "sslErrors"
QT_MOC_LITERAL(6, 52, 16), // "QList<QSslError>"
QT_MOC_LITERAL(7, 69, 12), // "sslErrorList"
QT_MOC_LITERAL(8, 82, 18), // "socketStateChanged"
QT_MOC_LITERAL(9, 101, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(10, 130, 5), // "state"
QT_MOC_LITERAL(11, 136, 11), // "socketError"
QT_MOC_LITERAL(12, 148, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(13, 177, 5), // "error"
QT_MOC_LITERAL(14, 183, 15), // "socketReadyRead"
QT_MOC_LITERAL(15, 199, 10), // "AuthMethod"
QT_MOC_LITERAL(16, 210, 8), // "AuthNone"
QT_MOC_LITERAL(17, 219, 9), // "AuthPlain"
QT_MOC_LITERAL(18, 229, 9), // "AuthLogin"
QT_MOC_LITERAL(19, 239, 11), // "AuthCramMd5"
QT_MOC_LITERAL(20, 251, 22), // "ConnectionTimeoutError"
QT_MOC_LITERAL(21, 274, 20), // "ResponseTimeoutError"
QT_MOC_LITERAL(22, 295, 20), // "SendDataTimeoutError"
QT_MOC_LITERAL(23, 316, 25), // "AuthenticationFailedError"
QT_MOC_LITERAL(24, 342, 11), // "ServerError"
QT_MOC_LITERAL(25, 354, 11), // "ClientError"
QT_MOC_LITERAL(26, 366, 14), // "ConnectionType"
QT_MOC_LITERAL(27, 381, 13), // "TcpConnection"
QT_MOC_LITERAL(28, 395, 13), // "SslConnection"
QT_MOC_LITERAL(29, 409, 13), // "TlsConnection"
QT_MOC_LITERAL(30, 423, 20), // "PeerVerificationType"
QT_MOC_LITERAL(31, 444, 10), // "VerifyNone"
QT_MOC_LITERAL(32, 455, 10) // "VerifyPeer"

    },
    "SimpleMail::Sender\0smtpError\0\0SmtpError\0"
    "e\0sslErrors\0QList<QSslError>\0sslErrorList\0"
    "socketStateChanged\0QAbstractSocket::SocketState\0"
    "state\0socketError\0QAbstractSocket::SocketError\0"
    "error\0socketReadyRead\0AuthMethod\0"
    "AuthNone\0AuthPlain\0AuthLogin\0AuthCramMd5\0"
    "ConnectionTimeoutError\0ResponseTimeoutError\0"
    "SendDataTimeoutError\0AuthenticationFailedError\0"
    "ServerError\0ClientError\0ConnectionType\0"
    "TcpConnection\0SslConnection\0TlsConnection\0"
    "PeerVerificationType\0VerifyNone\0"
    "VerifyPeer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleMail__Sender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       4,   52, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   45,    2, 0x09 /* Protected */,
      11,    1,   48,    2, 0x09 /* Protected */,
      14,    0,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // enums: name, flags, count, data
      15, 0x0,    4,   68,
       3, 0x0,    6,   76,
      26, 0x0,    3,   88,
      30, 0x0,    2,   94,

 // enum data: key, value
      16, uint(SimpleMail::Sender::AuthNone),
      17, uint(SimpleMail::Sender::AuthPlain),
      18, uint(SimpleMail::Sender::AuthLogin),
      19, uint(SimpleMail::Sender::AuthCramMd5),
      20, uint(SimpleMail::Sender::ConnectionTimeoutError),
      21, uint(SimpleMail::Sender::ResponseTimeoutError),
      22, uint(SimpleMail::Sender::SendDataTimeoutError),
      23, uint(SimpleMail::Sender::AuthenticationFailedError),
      24, uint(SimpleMail::Sender::ServerError),
      25, uint(SimpleMail::Sender::ClientError),
      27, uint(SimpleMail::Sender::TcpConnection),
      28, uint(SimpleMail::Sender::SslConnection),
      29, uint(SimpleMail::Sender::TlsConnection),
      31, uint(SimpleMail::Sender::VerifyNone),
      32, uint(SimpleMail::Sender::VerifyPeer),

       0        // eod
};

void SimpleMail::Sender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sender *_t = static_cast<Sender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->smtpError((*reinterpret_cast< SmtpError(*)>(_a[1]))); break;
        case 1: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 2: _t->socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 3: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->socketReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Sender::*_t)(SmtpError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sender::smtpError)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Sender::*_t)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sender::sslErrors)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SimpleMail::Sender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SimpleMail__Sender.data,
      qt_meta_data_SimpleMail__Sender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimpleMail::Sender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimpleMail::Sender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleMail__Sender.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SimpleMail::Sender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SimpleMail::Sender::smtpError(SmtpError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimpleMail::Sender::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
