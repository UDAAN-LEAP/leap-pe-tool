/****************************************************************************
** Meta object code from reading C++ file 'globalreplaceworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "globalreplaceworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'globalreplaceworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlobalReplaceWorker_t {
    QByteArrayData data[9];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlobalReplaceWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlobalReplaceWorker_t qt_meta_stringdata_GlobalReplaceWorker = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GlobalReplaceWorker"
QT_MOC_LITERAL(1, 20, 22), // "finishedReplacingWords"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 19), // "finishedWritingLogs"
QT_MOC_LITERAL(4, 64, 22), // "changeProgressBarValue"
QT_MOC_LITERAL(5, 87, 19), // "replaceWordsInFiles"
QT_MOC_LITERAL(6, 107, 9), // "writeLogs"
QT_MOC_LITERAL(7, 117, 12), // "saveBboxInfo"
QT_MOC_LITERAL(8, 130, 13) // "bboxInsertion"

    },
    "GlobalReplaceWorker\0finishedReplacingWords\0"
    "\0finishedWritingLogs\0changeProgressBarValue\0"
    "replaceWordsInFiles\0writeLogs\0"
    "saveBboxInfo\0bboxInsertion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalReplaceWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       8,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void GlobalReplaceWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlobalReplaceWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishedReplacingWords(); break;
        case 1: _t->finishedWritingLogs(); break;
        case 2: _t->changeProgressBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->replaceWordsInFiles(); break;
        case 4: _t->writeLogs(); break;
        case 5: _t->saveBboxInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->bboxInsertion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GlobalReplaceWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalReplaceWorker::finishedReplacingWords)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GlobalReplaceWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalReplaceWorker::finishedWritingLogs)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GlobalReplaceWorker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalReplaceWorker::changeProgressBarValue)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GlobalReplaceWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GlobalReplaceWorker.data,
    qt_meta_data_GlobalReplaceWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GlobalReplaceWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobalReplaceWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalReplaceWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GlobalReplaceWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GlobalReplaceWorker::finishedReplacingWords()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GlobalReplaceWorker::finishedWritingLogs()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GlobalReplaceWorker::changeProgressBarValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
