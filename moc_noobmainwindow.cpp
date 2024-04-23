/****************************************************************************
** Meta object code from reading C++ file 'noobmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "noobmainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'noobmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnoobMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSnoobMainWindowENDCLASS = QtMocHelpers::stringData(
    "noobMainWindow",
    "startClicked",
    "",
    "AClicked",
    "BClicked",
    "CClicked",
    "DClicked",
    "checkClicked",
    "nextClicked",
    "closeClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSnoobMainWindowENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[15];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[9];
    char stringdata7[13];
    char stringdata8[12];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSnoobMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSnoobMainWindowENDCLASS_t qt_meta_stringdata_CLASSnoobMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "noobMainWindow"
        QT_MOC_LITERAL(15, 12),  // "startClicked"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 8),  // "AClicked"
        QT_MOC_LITERAL(38, 8),  // "BClicked"
        QT_MOC_LITERAL(47, 8),  // "CClicked"
        QT_MOC_LITERAL(56, 8),  // "DClicked"
        QT_MOC_LITERAL(65, 12),  // "checkClicked"
        QT_MOC_LITERAL(78, 11),  // "nextClicked"
        QT_MOC_LITERAL(90, 12)   // "closeClicked"
    },
    "noobMainWindow",
    "startClicked",
    "",
    "AClicked",
    "BClicked",
    "CClicked",
    "DClicked",
    "checkClicked",
    "nextClicked",
    "closeClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnoobMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    0,   64,    2, 0x0a,    3 /* Public */,
       5,    0,   65,    2, 0x0a,    4 /* Public */,
       6,    0,   66,    2, 0x0a,    5 /* Public */,
       7,    0,   67,    2, 0x0a,    6 /* Public */,
       8,    0,   68,    2, 0x0a,    7 /* Public */,
       9,    0,   69,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject noobMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSnoobMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnoobMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnoobMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<noobMainWindow, std::true_type>,
        // method 'startClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'CClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void noobMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<noobMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startClicked(); break;
        case 1: _t->AClicked(); break;
        case 2: _t->BClicked(); break;
        case 3: _t->CClicked(); break;
        case 4: _t->DClicked(); break;
        case 5: _t->checkClicked(); break;
        case 6: _t->nextClicked(); break;
        case 7: _t->closeClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *noobMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *noobMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnoobMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int noobMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
