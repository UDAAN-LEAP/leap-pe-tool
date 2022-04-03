/****************************************************************************
** Meta object code from reading C++ file 'globalreplacedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "globalreplacedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'globalreplacedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlobalReplaceDialog_t {
    QByteArrayData data[21];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlobalReplaceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlobalReplaceDialog_t qt_meta_stringdata_GlobalReplaceDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GlobalReplaceDialog"
QT_MOC_LITERAL(1, 20, 16), // "fetchCheckedlist"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(4, 60, 12), // "QVector<int>"
QT_MOC_LITERAL(5, 73, 8), // "allPages"
QT_MOC_LITERAL(6, 82, 22), // "on_applyButton_clicked"
QT_MOC_LITERAL(7, 105, 19), // "displayOriginalList"
QT_MOC_LITERAL(8, 125, 16), // "QVector<QString>"
QT_MOC_LITERAL(9, 142, 13), // "replacedWords"
QT_MOC_LITERAL(10, 156, 24), // "leftCheckBoxStateChanged"
QT_MOC_LITERAL(11, 181, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 198, 24), // "on_previewButton_clicked"
QT_MOC_LITERAL(13, 223, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 245, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(15, 270, 4), // "arg1"
QT_MOC_LITERAL(16, 275, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(17, 302, 16), // "highlightChecked"
QT_MOC_LITERAL(18, 319, 4), // "item"
QT_MOC_LITERAL(19, 324, 31), // "getFilteredGlobalReplacementMap"
QT_MOC_LITERAL(20, 356, 18) // "uncheckedItemsList"

    },
    "GlobalReplaceDialog\0fetchCheckedlist\0"
    "\0QMap<QString,QString>\0QVector<int>\0"
    "allPages\0on_applyButton_clicked\0"
    "displayOriginalList\0QVector<QString>\0"
    "replacedWords\0leftCheckBoxStateChanged\0"
    "QListWidgetItem*\0on_previewButton_clicked\0"
    "on_pushButton_clicked\0on_checkBox_stateChanged\0"
    "arg1\0on_checkBox_2_stateChanged\0"
    "highlightChecked\0item\0"
    "getFilteredGlobalReplacementMap\0"
    "uncheckedItemsList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalReplaceDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,
      16,    1,   86,    2, 0x08 /* Private */,
      17,    1,   89,    2, 0x0a /* Public */,
      19,    0,   92,    2, 0x0a /* Public */,
      20,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, 0x80000000 | 11,   18,
    0x80000000 | 3,
    0x80000000 | 3,

       0        // eod
};

void GlobalReplaceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlobalReplaceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fetchCheckedlist((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        case 1: _t->on_applyButton_clicked(); break;
        case 2: _t->displayOriginalList((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 3: _t->leftCheckBoxStateChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_previewButton_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->highlightChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: { QMap<QString,QString> _r = _t->getFilteredGlobalReplacementMap();
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QMap<QString,QString> _r = _t->uncheckedItemsList();
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GlobalReplaceDialog::*)(QMap<QString,QString> , QVector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalReplaceDialog::fetchCheckedlist)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GlobalReplaceDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_GlobalReplaceDialog.data,
    qt_meta_data_GlobalReplaceDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GlobalReplaceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobalReplaceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalReplaceDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GlobalReplaceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GlobalReplaceDialog::fetchCheckedlist(QMap<QString,QString> _t1, QVector<int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
