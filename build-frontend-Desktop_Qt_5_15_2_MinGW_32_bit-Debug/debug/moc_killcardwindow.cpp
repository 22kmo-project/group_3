/****************************************************************************
** Meta object code from reading C++ file 'killcardwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/killcardwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'killcardwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KillCardWindow_t {
    QByteArrayData data[9];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KillCardWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KillCardWindow_t qt_meta_stringdata_KillCardWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KillCardWindow"
QT_MOC_LITERAL(1, 15, 27), // "on_confirmYesButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 26), // "on_confirmNoButton_clicked"
QT_MOC_LITERAL(4, 71, 26), // "on_confirmKillCard_clicked"
QT_MOC_LITERAL(5, 98, 10), // "lukitaSlot"
QT_MOC_LITERAL(6, 109, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 124, 5), // "reply"
QT_MOC_LITERAL(8, 130, 25) // "on_cancelKillCard_clicked"

    },
    "KillCardWindow\0on_confirmYesButton_clicked\0"
    "\0on_confirmNoButton_clicked\0"
    "on_confirmKillCard_clicked\0lukitaSlot\0"
    "QNetworkReply*\0reply\0on_cancelKillCard_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KillCardWindow[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void KillCardWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KillCardWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_confirmYesButton_clicked(); break;
        case 1: _t->on_confirmNoButton_clicked(); break;
        case 2: _t->on_confirmKillCard_clicked(); break;
        case 3: _t->lukitaSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->on_cancelKillCard_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KillCardWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_KillCardWindow.data,
    qt_meta_data_KillCardWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KillCardWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KillCardWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KillCardWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KillCardWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
