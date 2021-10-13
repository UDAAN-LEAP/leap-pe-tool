/****************************************************************************
** Meta object code from reading C++ file 'DiffView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DiffView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DiffView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DiffView_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DiffView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DiffView_t qt_meta_stringdata_DiffView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DiffView"
QT_MOC_LITERAL(1, 9, 21), // "on_PrevButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "Load_comparePage"
QT_MOC_LITERAL(4, 49, 6), // "string"
QT_MOC_LITERAL(5, 56, 4), // "page"
QT_MOC_LITERAL(6, 61, 21), // "on_NextButton_clicked"
QT_MOC_LITERAL(7, 83, 8) // "UpdateUI"

    },
    "DiffView\0on_PrevButton_clicked\0\0"
    "Load_comparePage\0string\0page\0"
    "on_NextButton_clicked\0UpdateUI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DiffView[] = {

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
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DiffView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DiffView *_t = static_cast<DiffView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PrevButton_clicked(); break;
        case 1: _t->Load_comparePage((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->on_NextButton_clicked(); break;
        case 3: _t->UpdateUI(); break;
        default: ;
        }
    }
}

const QMetaObject DiffView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DiffView.data,
      qt_meta_data_DiffView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DiffView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DiffView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DiffView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DiffView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
