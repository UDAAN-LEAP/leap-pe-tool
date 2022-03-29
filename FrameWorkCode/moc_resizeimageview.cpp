/****************************************************************************
** Meta object code from reading C++ file 'resizeimageview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "resizeimageview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resizeimageview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResizeImageView_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResizeImageView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResizeImageView_t qt_meta_stringdata_ResizeImageView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ResizeImageView"
QT_MOC_LITERAL(1, 16, 28), // "on_widthSpinBox_valueChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "arg1"
QT_MOC_LITERAL(4, 51, 28), // "on_hightSpinBox_valueChanged"
QT_MOC_LITERAL(5, 80, 13), // "on_Ok_clicked"
QT_MOC_LITERAL(6, 94, 17) // "on_Cancel_clicked"

    },
    "ResizeImageView\0on_widthSpinBox_valueChanged\0"
    "\0arg1\0on_hightSpinBox_valueChanged\0"
    "on_Ok_clicked\0on_Cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResizeImageView[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResizeImageView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResizeImageView *_t = static_cast<ResizeImageView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_widthSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_hightSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_Ok_clicked(); break;
        case 3: _t->on_Cancel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ResizeImageView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ResizeImageView.data,
      qt_meta_data_ResizeImageView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ResizeImageView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResizeImageView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResizeImageView.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ResizeImageView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
