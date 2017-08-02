/****************************************************************************
** Meta object code from reading C++ file 'dataformatter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GetThermal/inc/dataformatter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataformatter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataFormatter_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataFormatter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataFormatter_t qt_meta_stringdata_DataFormatter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DataFormatter"
QT_MOC_LITERAL(1, 14, 25), // "psuedocolorPaletteChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "Palette"
QT_MOC_LITERAL(4, 49, 3), // "val"
QT_MOC_LITERAL(5, 53, 13), // "minValChanged"
QT_MOC_LITERAL(6, 67, 13), // "maxValChanged"
QT_MOC_LITERAL(7, 81, 18), // "pseudocolorPalette"
QT_MOC_LITERAL(8, 100, 6), // "minVal"
QT_MOC_LITERAL(9, 107, 6), // "maxVal"
QT_MOC_LITERAL(10, 114, 9), // "IronBlack"
QT_MOC_LITERAL(11, 124, 7), // "Rainbow"
QT_MOC_LITERAL(12, 132, 9) // "Grayscale"

    },
    "DataFormatter\0psuedocolorPaletteChanged\0"
    "\0Palette\0val\0minValChanged\0maxValChanged\0"
    "pseudocolorPalette\0minVal\0maxVal\0"
    "IronBlack\0Rainbow\0Grayscale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataFormatter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   38, // properties
       1,   50, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UShort,    4,
    QMetaType::Void, QMetaType::UShort,    4,

 // properties: name, type, flags
       7, 0x80000000 | 3, 0x0049500b,
       8, QMetaType::UShort, 0x00495001,
       9, QMetaType::UShort, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,

 // enums: name, flags, count, data
       3, 0x0,    3,   54,

 // enum data: key, value
      10, uint(DataFormatter::IronBlack),
      11, uint(DataFormatter::Rainbow),
      12, uint(DataFormatter::Grayscale),

       0        // eod
};

void DataFormatter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataFormatter *_t = static_cast<DataFormatter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->psuedocolorPaletteChanged((*reinterpret_cast< Palette(*)>(_a[1]))); break;
        case 1: _t->minValChanged((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 2: _t->maxValChanged((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataFormatter::*_t)(Palette );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataFormatter::psuedocolorPaletteChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataFormatter::*_t)(ushort );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataFormatter::minValChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataFormatter::*_t)(ushort );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataFormatter::maxValChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        DataFormatter *_t = static_cast<DataFormatter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Palette*>(_v) = _t->m_pseudocolor_palette; break;
        case 1: *reinterpret_cast< ushort*>(_v) = _t->getMinVal(); break;
        case 2: *reinterpret_cast< ushort*>(_v) = _t->getMaxVal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        DataFormatter *_t = static_cast<DataFormatter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_pseudocolor_palette != *reinterpret_cast< Palette*>(_v)) {
                _t->m_pseudocolor_palette = *reinterpret_cast< Palette*>(_v);
                Q_EMIT _t->psuedocolorPaletteChanged(_t->m_pseudocolor_palette);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject DataFormatter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataFormatter.data,
      qt_meta_data_DataFormatter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataFormatter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataFormatter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataFormatter.stringdata0))
        return static_cast<void*>(const_cast< DataFormatter*>(this));
    return QObject::qt_metacast(_clname);
}

int DataFormatter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataFormatter::psuedocolorPaletteChanged(Palette _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataFormatter::minValChanged(ushort _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataFormatter::maxValChanged(ushort _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
