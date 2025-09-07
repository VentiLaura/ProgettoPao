/****************************************************************************
** Meta object code from reading C++ file 'DetailsPageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "View/DetailsPageWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DetailsPageWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_DetailsPageWidget_t {
    uint offsetsAndSizes[6];
    char stringdata0[18];
    char stringdata1[12];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DetailsPageWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DetailsPageWidget_t qt_meta_stringdata_DetailsPageWidget = {
    {
        QT_MOC_LITERAL(0, 17),  // "DetailsPageWidget"
        QT_MOC_LITERAL(18, 11),  // "quitClicked"
        QT_MOC_LITERAL(30, 0)   // ""
    },
    "DetailsPageWidget",
    "quitClicked",
    ""
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DetailsPageWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DetailsPageWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DetailsPageWidget.offsetsAndSizes,
    qt_meta_data_DetailsPageWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DetailsPageWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DetailsPageWidget, std::true_type>,
        // method 'quitClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DetailsPageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DetailsPageWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->quitClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DetailsPageWidget::*)();
            if (_t _q_method = &DetailsPageWidget::quitClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *DetailsPageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetailsPageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetailsPageWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DetailsPageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DetailsPageWidget::quitClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
