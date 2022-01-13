/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SimpleMail/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleMail__Server_t {
    QByteArrayData data[27];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleMail__Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleMail__Server_t qt_meta_stringdata_SimpleMail__Server = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SimpleMail::Server"
QT_MOC_LITERAL(1, 19, 9), // "smtpError"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "SmtpError"
QT_MOC_LITERAL(4, 40, 1), // "e"
QT_MOC_LITERAL(5, 42, 11), // "description"
QT_MOC_LITERAL(6, 54, 9), // "sslErrors"
QT_MOC_LITERAL(7, 64, 16), // "QList<QSslError>"
QT_MOC_LITERAL(8, 81, 12), // "sslErrorList"
QT_MOC_LITERAL(9, 94, 10), // "AuthMethod"
QT_MOC_LITERAL(10, 105, 8), // "AuthNone"
QT_MOC_LITERAL(11, 114, 9), // "AuthPlain"
QT_MOC_LITERAL(12, 124, 9), // "AuthLogin"
QT_MOC_LITERAL(13, 134, 11), // "AuthCramMd5"
QT_MOC_LITERAL(14, 146, 22), // "ConnectionTimeoutError"
QT_MOC_LITERAL(15, 169, 20), // "ResponseTimeoutError"
QT_MOC_LITERAL(16, 190, 20), // "SendDataTimeoutError"
QT_MOC_LITERAL(17, 211, 25), // "AuthenticationFailedError"
QT_MOC_LITERAL(18, 237, 11), // "ServerError"
QT_MOC_LITERAL(19, 249, 11), // "ClientError"
QT_MOC_LITERAL(20, 261, 14), // "ConnectionType"
QT_MOC_LITERAL(21, 276, 13), // "TcpConnection"
QT_MOC_LITERAL(22, 290, 13), // "SslConnection"
QT_MOC_LITERAL(23, 304, 13), // "TlsConnection"
QT_MOC_LITERAL(24, 318, 20), // "PeerVerificationType"
QT_MOC_LITERAL(25, 339, 10), // "VerifyNone"
QT_MOC_LITERAL(26, 350, 10) // "VerifyPeer"

    },
    "SimpleMail::Server\0smtpError\0\0SmtpError\0"
    "e\0description\0sslErrors\0QList<QSslError>\0"
    "sslErrorList\0AuthMethod\0AuthNone\0"
    "AuthPlain\0AuthLogin\0AuthCramMd5\0"
    "ConnectionTimeoutError\0ResponseTimeoutError\0"
    "SendDataTimeoutError\0AuthenticationFailedError\0"
    "ServerError\0ClientError\0ConnectionType\0"
    "TcpConnection\0SslConnection\0TlsConnection\0"
    "PeerVerificationType\0VerifyNone\0"
    "VerifyPeer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleMail__Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       4,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // enums: name, alias, flags, count, data
       9,    9, 0x0,    4,   52,
       3,    3, 0x0,    6,   60,
      20,   20, 0x0,    3,   72,
      24,   24, 0x0,    2,   78,

 // enum data: key, value
      10, uint(SimpleMail::Server::AuthNone),
      11, uint(SimpleMail::Server::AuthPlain),
      12, uint(SimpleMail::Server::AuthLogin),
      13, uint(SimpleMail::Server::AuthCramMd5),
      14, uint(SimpleMail::Server::ConnectionTimeoutError),
      15, uint(SimpleMail::Server::ResponseTimeoutError),
      16, uint(SimpleMail::Server::SendDataTimeoutError),
      17, uint(SimpleMail::Server::AuthenticationFailedError),
      18, uint(SimpleMail::Server::ServerError),
      19, uint(SimpleMail::Server::ClientError),
      21, uint(SimpleMail::Server::TcpConnection),
      22, uint(SimpleMail::Server::SslConnection),
      23, uint(SimpleMail::Server::TlsConnection),
      25, uint(SimpleMail::Server::VerifyNone),
      26, uint(SimpleMail::Server::VerifyPeer),

       0        // eod
};

void SimpleMail::Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->smtpError((*reinterpret_cast< SmtpError(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(SmtpError , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::smtpError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::sslErrors)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SimpleMail::Server::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SimpleMail__Server.data,
    qt_meta_data_SimpleMail__Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SimpleMail::Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimpleMail::Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleMail__Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SimpleMail::Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SimpleMail::Server::smtpError(SmtpError _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimpleMail::Server::sslErrors(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
