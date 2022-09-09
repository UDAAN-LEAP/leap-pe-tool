/****************************************************************************
** Meta object code from reading C++ file 'undoglobalreplace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "undoglobalreplace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'undoglobalreplace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UndoGlobalReplace_t {
    QByteArrayData data[10];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UndoGlobalReplace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UndoGlobalReplace_t qt_meta_stringdata_UndoGlobalReplace = {
    {
QT_MOC_LITERAL(0, 0, 17), // "UndoGlobalReplace"
QT_MOC_LITERAL(1, 18, 27), // "displayListForUndoOperation"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(4, 69, 13), // "reversedGRMap"
QT_MOC_LITERAL(5, 83, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 107, 16), // "highlightChecked"
QT_MOC_LITERAL(7, 124, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 141, 22), // "on_applyButton_clicked"
QT_MOC_LITERAL(9, 164, 15) // "getFinalUndoMap"

    },
    "UndoGlobalReplace\0displayListForUndoOperation\0"
    "\0QMap<QString,QString>\0reversedGRMap\0"
    "on_cancelButton_clicked\0highlightChecked\0"
    "QListWidgetItem*\0on_applyButton_clicked\0"
    "getFinalUndoMap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UndoGlobalReplace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x0a /* Public */,
       8,    0,   46,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Bool,
    0x80000000 | 3,

       0        // eod
};

void UndoGlobalReplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UndoGlobalReplace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayListForUndoOperation((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->highlightChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: { bool _r = _t->on_applyButton_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QMap<QString,QString> _r = _t->getFinalUndoMap();
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UndoGlobalReplace::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_UndoGlobalReplace.data,
    qt_meta_data_UndoGlobalReplace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UndoGlobalReplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UndoGlobalReplace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UndoGlobalReplace.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UndoGlobalReplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
