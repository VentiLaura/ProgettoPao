/****************************************************************************
** Meta object code from reading C++ file 'PageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "View/PageWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_PageWidget_t {
    uint offsetsAndSizes[12];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[8];
    char stringdata5[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PageWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PageWidget_t qt_meta_stringdata_PageWidget = {
    {
        QT_MOC_LITERAL(0, 10),  // "PageWidget"
        QT_MOC_LITERAL(11, 18),  // "showProductDetails"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 17),  // "product::Product*"
        QT_MOC_LITERAL(49, 7),  // "product"
        QT_MOC_LITERAL(57, 8)   // "showGrid"
    },
    "PageWidget",
    "showProductDetails",
    "",
    "product::Product*",
    "product",
    "showGrid"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PageWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       5,    0,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PageWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PageWidget.offsetsAndSizes,
    qt_meta_data_PageWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PageWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PageWidget, std::true_type>,
        // method 'showProductDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<product::Product *, std::false_type>,
        // method 'showGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PageWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showProductDetails((*reinterpret_cast< std::add_pointer_t<product::Product*>>(_a[1]))); break;
        case 1: _t->showGrid(); break;
        default: ;
        }
    }
}

const QMetaObject *PageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PageWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
