/****************************************************************************
** Meta object code from reading C++ file 'uvcvideoproducer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GetThermal/inc/uvcvideoproducer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uvcvideoproducer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UvcVideoProducer_t {
    QByteArrayData data[12];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UvcVideoProducer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UvcVideoProducer_t qt_meta_stringdata_UvcVideoProducer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UvcVideoProducer"
QT_MOC_LITERAL(1, 17, 14), // "surfaceChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(4, 56, 7), // "surface"
QT_MOC_LITERAL(5, 64, 10), // "uvcChanged"
QT_MOC_LITERAL(6, 75, 15), // "UvcAcquisition*"
QT_MOC_LITERAL(7, 91, 3), // "uvc"
QT_MOC_LITERAL(8, 95, 25), // "onNewVideoContentReceived"
QT_MOC_LITERAL(9, 121, 11), // "QVideoFrame"
QT_MOC_LITERAL(10, 133, 5), // "frame"
QT_MOC_LITERAL(11, 139, 12) // "videoSurface"

    },
    "UvcVideoProducer\0surfaceChanged\0\0"
    "QAbstractVideoSurface*\0surface\0"
    "uvcChanged\0UvcAcquisition*\0uvc\0"
    "onNewVideoContentReceived\0QVideoFrame\0"
    "frame\0videoSurface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UvcVideoProducer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,

 // properties: name, type, flags
      11, 0x80000000 | 3, 0x0049510b,
       7, 0x80000000 | 6, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void UvcVideoProducer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UvcVideoProducer *_t = static_cast<UvcVideoProducer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->surfaceChanged((*reinterpret_cast< QAbstractVideoSurface*(*)>(_a[1]))); break;
        case 1: _t->uvcChanged((*reinterpret_cast< UvcAcquisition*(*)>(_a[1]))); break;
        case 2: _t->onNewVideoContentReceived((*reinterpret_cast< const QVideoFrame(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UvcAcquisition* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoFrame >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UvcVideoProducer::*_t)(QAbstractVideoSurface * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UvcVideoProducer::surfaceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UvcVideoProducer::*_t)(UvcAcquisition * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UvcVideoProducer::uvcChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UvcAcquisition* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UvcVideoProducer *_t = static_cast<UvcVideoProducer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->m_surface; break;
        case 1: *reinterpret_cast< UvcAcquisition**>(_v) = _t->m_uvc; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UvcVideoProducer *_t = static_cast<UvcVideoProducer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVideoSurface(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        case 1: _t->setUvc(*reinterpret_cast< UvcAcquisition**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject UvcVideoProducer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UvcVideoProducer.data,
      qt_meta_data_UvcVideoProducer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UvcVideoProducer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UvcVideoProducer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UvcVideoProducer.stringdata0))
        return static_cast<void*>(const_cast< UvcVideoProducer*>(this));
    return QObject::qt_metacast(_clname);
}

int UvcVideoProducer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UvcVideoProducer::surfaceChanged(QAbstractVideoSurface * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UvcVideoProducer::uvcChanged(UvcAcquisition * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
