/****************************************************************************
** Meta object code from reading C++ file 'adminform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../untitled/adminform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminForm_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminForm_t qt_meta_stringdata_AdminForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AdminForm"
QT_MOC_LITERAL(1, 10, 14), // "loginRequested"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "registerRequested"
QT_MOC_LITERAL(4, 44, 8), // "accepted"
QT_MOC_LITERAL(5, 53, 22), // "on_loginButton_clicked"
QT_MOC_LITERAL(6, 76, 25), // "on_registerButton_clicked"
QT_MOC_LITERAL(7, 102, 23) // "on_acceptButton_clicked"

    },
    "AdminForm\0loginRequested\0\0registerRequested\0"
    "accepted\0on_loginButton_clicked\0"
    "on_registerButton_clicked\0"
    "on_acceptButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginRequested(); break;
        case 1: _t->registerRequested(); break;
        case 2: _t->accepted(); break;
        case 3: _t->on_loginButton_clicked(); break;
        case 4: _t->on_registerButton_clicked(); break;
        case 5: _t->on_acceptButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminForm::loginRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminForm::registerRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdminForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminForm::accepted)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AdminForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AdminForm.data,
    qt_meta_data_AdminForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AdminForm::loginRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminForm::registerRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AdminForm::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
