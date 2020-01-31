/****************************************************************************
** Meta object code from reading C++ file 'serialportmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BeerwatcherQt/serialportmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortManager_t {
    QByteArrayData data[19];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortManager_t qt_meta_stringdata_SerialPortManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPortManager"
QT_MOC_LITERAL(1, 18, 4), // "temp"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "data"
QT_MOC_LITERAL(4, 29, 10), // "vibrations"
QT_MOC_LITERAL(5, 40, 15), // "handleReadyRead"
QT_MOC_LITERAL(6, 56, 13), // "handleTimeout"
QT_MOC_LITERAL(7, 70, 11), // "handleError"
QT_MOC_LITERAL(8, 82, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 111, 5), // "error"
QT_MOC_LITERAL(10, 117, 14), // "availablePorts"
QT_MOC_LITERAL(11, 132, 9), // "getVendor"
QT_MOC_LITERAL(12, 142, 3), // "tty"
QT_MOC_LITERAL(13, 146, 15), // "getManufacturer"
QT_MOC_LITERAL(14, 162, 20), // "getProductIdentifier"
QT_MOC_LITERAL(15, 183, 15), // "getSerialNumber"
QT_MOC_LITERAL(16, 199, 14), // "setCurrentPort"
QT_MOC_LITERAL(17, 214, 5), // "write"
QT_MOC_LITERAL(18, 220, 7) // "message"

    },
    "SerialPortManager\0temp\0\0data\0vibrations\0"
    "handleReadyRead\0handleTimeout\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "availablePorts\0getVendor\0tty\0"
    "getManufacturer\0getProductIdentifier\0"
    "getSerialNumber\0setCurrentPort\0write\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   80,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    1,   82,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   85,    2, 0x02 /* Public */,
      11,    1,   86,    2, 0x02 /* Public */,
      13,    1,   89,    2, 0x02 /* Public */,
      14,    1,   92,    2, 0x02 /* Public */,
      15,    1,   95,    2, 0x02 /* Public */,
      16,    1,   98,    2, 0x02 /* Public */,
      17,    1,  101,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // methods: parameters
    QMetaType::QVariant,
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QByteArray,   18,

       0        // eod
};

void SerialPortManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPortManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->temp((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->vibrations((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->handleReadyRead(); break;
        case 3: _t->handleTimeout(); break;
        case 4: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 5: { QVariant _r = _t->availablePorts();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getVendor((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getManufacturer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getProductIdentifier((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getSerialNumber((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setCurrentPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialPortManager::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortManager::temp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialPortManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortManager::vibrations)) {
                *result = 1;
                return;
            }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SerialPortManager::temp(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPortManager::vibrations(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
