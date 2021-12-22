/****************************************************************************
** Meta object code from reading C++ file 'globalreplacedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "globalreplacedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'globalreplacedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlobalReplaceDialog_t {
    QByteArrayData data[16];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlobalReplaceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlobalReplaceDialog_t qt_meta_stringdata_GlobalReplaceDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GlobalReplaceDialog"
QT_MOC_LITERAL(1, 20, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 22), // "on_applyButton_clicked"
QT_MOC_LITERAL(4, 68, 19), // "displayOriginalList"
QT_MOC_LITERAL(5, 88, 16), // "QVector<QString>"
QT_MOC_LITERAL(6, 105, 13), // "replacedWords"
QT_MOC_LITERAL(7, 119, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 141, 24), // "leftCheckBoxStateChanged"
QT_MOC_LITERAL(9, 166, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 183, 18), // "on_Preview_clicked"
QT_MOC_LITERAL(11, 202, 23), // "on_uploadButton_clicked"
QT_MOC_LITERAL(12, 226, 16), // "highlightChecked"
QT_MOC_LITERAL(13, 243, 4), // "item"
QT_MOC_LITERAL(14, 248, 31), // "getFilteredGlobalReplacementMap"
QT_MOC_LITERAL(15, 280, 21) // "QMap<QString,QString>"

    },
    "GlobalReplaceDialog\0on_cancelButton_clicked\0"
    "\0on_applyButton_clicked\0displayOriginalList\0"
    "QVector<QString>\0replacedWords\0"
    "on_pushButton_clicked\0leftCheckBoxStateChanged\0"
    "QListWidgetItem*\0on_Preview_clicked\0"
    "on_uploadButton_clicked\0highlightChecked\0"
    "item\0getFilteredGlobalReplacementMap\0"
    "QMap<QString,QString>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalReplaceDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    1,   70,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   13,
    0x80000000 | 15,

       0        // eod
};

void GlobalReplaceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlobalReplaceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cancelButton_clicked(); break;
        case 1: _t->on_applyButton_clicked(); break;
        case 2: _t->displayOriginalList((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->leftCheckBoxStateChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_Preview_clicked(); break;
        case 6: _t->on_uploadButton_clicked(); break;
        case 7: _t->highlightChecked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: { QMap<QString,QString> _r = _t->getFilteredGlobalReplacementMap();
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GlobalReplaceDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
