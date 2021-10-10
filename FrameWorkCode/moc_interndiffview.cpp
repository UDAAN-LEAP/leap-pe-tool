/****************************************************************************
** Meta object code from reading C++ file 'interndiffview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "interndiffview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interndiffview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InternDiffView_t {
    QByteArrayData data[15];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InternDiffView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InternDiffView_t qt_meta_stringdata_InternDiffView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "InternDiffView"
QT_MOC_LITERAL(1, 15, 21), // "on_NextButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "Load_comparePage"
QT_MOC_LITERAL(4, 55, 6), // "string"
QT_MOC_LITERAL(5, 62, 4), // "page"
QT_MOC_LITERAL(6, 67, 21), // "on_prevButton_clicked"
QT_MOC_LITERAL(7, 89, 13), // "GetPageNumber"
QT_MOC_LITERAL(8, 103, 13), // "localFilename"
QT_MOC_LITERAL(9, 117, 7), // "string*"
QT_MOC_LITERAL(10, 125, 2), // "no"
QT_MOC_LITERAL(11, 128, 7), // "size_t*"
QT_MOC_LITERAL(12, 136, 3), // "loc"
QT_MOC_LITERAL(13, 140, 8), // "QString*"
QT_MOC_LITERAL(14, 149, 3) // "ext"

    },
    "InternDiffView\0on_NextButton_clicked\0"
    "\0Load_comparePage\0string\0page\0"
    "on_prevButton_clicked\0GetPageNumber\0"
    "localFilename\0string*\0no\0size_t*\0loc\0"
    "QString*\0ext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InternDiffView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    4,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 4, 0x80000000 | 9, 0x80000000 | 11, 0x80000000 | 13,    8,   10,   12,   14,

       0        // eod
};

void InternDiffView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InternDiffView *_t = static_cast<InternDiffView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_NextButton_clicked(); break;
        case 1: _t->Load_comparePage((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->on_prevButton_clicked(); break;
        case 3: { int _r = _t->GetPageNumber((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string*(*)>(_a[2])),(*reinterpret_cast< size_t*(*)>(_a[3])),(*reinterpret_cast< QString*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject InternDiffView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_InternDiffView.data,
      qt_meta_data_InternDiffView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InternDiffView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InternDiffView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InternDiffView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int InternDiffView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
