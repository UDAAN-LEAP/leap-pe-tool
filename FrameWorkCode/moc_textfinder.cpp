/****************************************************************************
** Meta object code from reading C++ file 'textfinder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "textfinder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textfinder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextFinder_t {
    QByteArrayData data[14];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextFinder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextFinder_t qt_meta_stringdata_TextFinder = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextFinder"
QT_MOC_LITERAL(1, 11, 25), // "on_findNextButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 29), // "on_findPreviousButton_clicked"
QT_MOC_LITERAL(4, 68, 24), // "on_replaceButton_clicked"
QT_MOC_LITERAL(5, 93, 27), // "on_replaceAllButton_clicked"
QT_MOC_LITERAL(6, 121, 13), // "keyPressEvent"
QT_MOC_LITERAL(7, 135, 10), // "QKeyEvent*"
QT_MOC_LITERAL(8, 146, 12), // "toDevanagari"
QT_MOC_LITERAL(9, 159, 6), // "string"
QT_MOC_LITERAL(10, 166, 11), // "eventFilter"
QT_MOC_LITERAL(11, 178, 7), // "watched"
QT_MOC_LITERAL(12, 186, 7), // "QEvent*"
QT_MOC_LITERAL(13, 194, 5) // "event"

    },
    "TextFinder\0on_findNextButton_clicked\0"
    "\0on_findPreviousButton_clicked\0"
    "on_replaceButton_clicked\0"
    "on_replaceAllButton_clicked\0keyPressEvent\0"
    "QKeyEvent*\0toDevanagari\0string\0"
    "eventFilter\0watched\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextFinder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    2,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::QString, 0x80000000 | 9,    2,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 12,   11,   13,

       0        // eod
};

void TextFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextFinder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_findNextButton_clicked(); break;
        case 1: _t->on_findPreviousButton_clicked(); break;
        case 2: _t->on_replaceButton_clicked(); break;
        case 3: _t->on_replaceAllButton_clicked(); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: { QString _r = _t->toDevanagari((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextFinder::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_TextFinder.data,
    qt_meta_data_TextFinder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextFinder.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TextFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
