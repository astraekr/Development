/****************************************************************************
** Meta object code from reading C++ file 'bosonvariation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GetThermal/inc/bosonvariation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bosonvariation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BosonVariation_t {
    QByteArrayData data[19];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BosonVariation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BosonVariation_t qt_meta_stringdata_BosonVariation = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BosonVariation"
QT_MOC_LITERAL(1, 15, 25), // "cameraInternalTempChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 4), // "temp"
QT_MOC_LITERAL(4, 47, 17), // "colorLutIdChanged"
QT_MOC_LITERAL(5, 65, 13), // "COLORLUT_ID_E"
QT_MOC_LITERAL(6, 79, 3), // "val"
QT_MOC_LITERAL(7, 83, 10), // "performFfc"
QT_MOC_LITERAL(8, 94, 10), // "colorLutId"
QT_MOC_LITERAL(9, 105, 18), // "cameraSerialNumber"
QT_MOC_LITERAL(10, 124, 16), // "cameraPartNumber"
QT_MOC_LITERAL(11, 141, 18), // "sensorSerialNumber"
QT_MOC_LITERAL(12, 160, 16), // "sensorPartNumber"
QT_MOC_LITERAL(13, 177, 11), // "softwareRev"
QT_MOC_LITERAL(14, 189, 19), // "cameraInternalTempC"
QT_MOC_LITERAL(15, 209, 21), // "supportsHwPseudoColor"
QT_MOC_LITERAL(16, 231, 18), // "supportsRadiometry"
QT_MOC_LITERAL(17, 250, 13), // "defaultFormat"
QT_MOC_LITERAL(18, 264, 19) // "QVideoSurfaceFormat"

    },
    "BosonVariation\0cameraInternalTempChanged\0"
    "\0temp\0colorLutIdChanged\0COLORLUT_ID_E\0"
    "val\0performFfc\0colorLutId\0cameraSerialNumber\0"
    "cameraPartNumber\0sensorSerialNumber\0"
    "sensorPartNumber\0softwareRev\0"
    "cameraInternalTempC\0supportsHwPseudoColor\0"
    "supportsRadiometry\0defaultFormat\0"
    "QVideoSurfaceFormat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BosonVariation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
      10,   36, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       8, 0x80000000 | 5, 0x0049500b,
       9, QMetaType::QString, 0x00095001,
      10, QMetaType::QString, 0x00095001,
      11, QMetaType::QString, 0x00095001,
      12, QMetaType::QString, 0x00095001,
      13, QMetaType::QString, 0x00095001,
      14, QMetaType::Float, 0x00495001,
      15, QMetaType::Bool, 0x00095001,
      16, QMetaType::Bool, 0x00095001,
      17, 0x80000000 | 18, 0x00095009,

 // properties: notify_signal_id
       1,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void BosonVariation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BosonVariation *_t = static_cast<BosonVariation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cameraInternalTempChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->colorLutIdChanged((*reinterpret_cast< COLORLUT_ID_E(*)>(_a[1]))); break;
        case 2: _t->performFfc(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< COLORLUT_ID_E >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BosonVariation::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BosonVariation::cameraInternalTempChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BosonVariation::*_t)(COLORLUT_ID_E );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BosonVariation::colorLutIdChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< COLORLUT_ID_E >(); break;
        case 9:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoSurfaceFormat >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BosonVariation *_t = static_cast<BosonVariation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< COLORLUT_ID_E*>(_v) = _t->bind_get<FLR_COLORLUT_ID_E,COLORLUT_ID_E>(colorLutGetId)(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getCameraSerialNumber(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getCameraPartNumber(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getSensorSerialNumber(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getSensorPartNumber(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getSoftwareRev(); break;
        case 6: *reinterpret_cast< float*>(_v) = _t->getCameraInternalTempC(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getSupportsHwPseudoColor(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->getSupportsRadiometry(); break;
        case 9: *reinterpret_cast< QVideoSurfaceFormat*>(_v) = _t->getDefaultFormat(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BosonVariation *_t = static_cast<BosonVariation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->bind_set<FLR_COLORLUT_ID_E,COLORLUT_ID_E>(colorLutSetId,(bind(&BosonVariation::colorLutIdChanged,_t,_1)))(*reinterpret_cast< COLORLUT_ID_E*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BosonVariation::staticMetaObject = {
    { &AbstractCCInterface::staticMetaObject, qt_meta_stringdata_BosonVariation.data,
      qt_meta_data_BosonVariation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BosonVariation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BosonVariation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BosonVariation.stringdata0))
        return static_cast<void*>(const_cast< BosonVariation*>(this));
    return AbstractCCInterface::qt_metacast(_clname);
}

int BosonVariation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCCInterface::qt_metacall(_c, _id, _a);
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
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BosonVariation::cameraInternalTempChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BosonVariation::colorLutIdChanged(COLORLUT_ID_E _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
