/****************************************************************************
** Meta object code from reading C++ file 'serialportmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeerwatcherQt/serialportmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortManager_t {
    QByteArrayData data[13];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortManager_t qt_meta_stringdata_SerialPortManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPortManager"
QT_MOC_LITERAL(1, 18, 14), // "availablePorts"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "getVendor"
QT_MOC_LITERAL(4, 44, 3), // "tty"
QT_MOC_LITERAL(5, 48, 15), // "getManufacturer"
QT_MOC_LITERAL(6, 64, 20), // "getProductIdentifier"
QT_MOC_LITERAL(7, 85, 15), // "getSerialNumber"
QT_MOC_LITERAL(8, 101, 14), // "setCurrentPort"
QT_MOC_LITERAL(9, 116, 5), // "write"
QT_MOC_LITERAL(10, 122, 7), // "message"
QT_MOC_LITERAL(11, 130, 4), // "read"
QT_MOC_LITERAL(12, 135, 4) // "send"

    },
    "SerialPortManager\0availablePorts\0\0"
    "getVendor\0tty\0getManufacturer\0"
    "getProductIdentifier\0getSerialNumber\0"
    "setCurrentPort\0write\0message\0read\0"
    "send"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortManager[] = {

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

 // methods: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x02 /* Public */,
       3,    1,   60,    2, 0x02 /* Public */,
       5,    1,   63,    2, 0x02 /* Public */,
       6,    1,   66,    2, 0x02 /* Public */,
       7,    1,   69,    2, 0x02 /* Public */,
       8,    1,   72,    2, 0x02 /* Public */,
       9,    1,   75,    2, 0x02 /* Public */,
      11,    0,   78,    2, 0x02 /* Public */,
      12,    1,   79,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QVariant,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,

       0        // eod
};

void SerialPortManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPortManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->availablePorts();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getVendor((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getManufacturer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getProductIdentifier((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getSerialNumber((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setCurrentPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->read(); break;
        case 8: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialPortManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SerialPortManager.data,
    qt_meta_data_SerialPortManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialPortManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
