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
    QByteArrayData data[14];
    char stringdata0[232];
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
QT_MOC_LITERAL(7, 89, 9), // "Update_UI"
QT_MOC_LITERAL(8, 99, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(9, 131, 8), // "position"
QT_MOC_LITERAL(10, 140, 25), // "on_zoom_In_Button_clicked"
QT_MOC_LITERAL(11, 166, 26), // "on_zoom_Out_Button_clicked"
QT_MOC_LITERAL(12, 193, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(13, 226, 5) // "value"

    },
    "InternDiffView\0on_NextButton_clicked\0"
    "\0Load_comparePage\0string\0page\0"
    "on_prevButton_clicked\0Update_UI\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_zoom_In_Button_clicked\0"
    "on_zoom_Out_Button_clicked\0"
    "on_horizontalSlider_valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InternDiffView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

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
        case 3: _t->Update_UI(); break;
        case 4: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_zoom_In_Button_clicked(); break;
        case 6: _t->on_zoom_Out_Button_clicked(); break;
        case 7: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
