/****************************************************************************
** Meta object code from reading C++ file 'nmea_parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nmea_parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmea_parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nmea_parser_t {
    QByteArrayData data[13];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nmea_parser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nmea_parser_t qt_meta_stringdata_nmea_parser = {
    {
QT_MOC_LITERAL(0, 0, 11), // "nmea_parser"
QT_MOC_LITERAL(1, 12, 16), // "downloadFinished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "pipeParsedData"
QT_MOC_LITERAL(4, 45, 4), // "data"
QT_MOC_LITERAL(5, 50, 16), // "SIGNALqueryLocus"
QT_MOC_LITERAL(6, 67, 17), // "updateProgressBar"
QT_MOC_LITERAL(7, 85, 8), // "progress"
QT_MOC_LITERAL(8, 94, 9), // "appendRed"
QT_MOC_LITERAL(9, 104, 3), // "msg"
QT_MOC_LITERAL(10, 108, 10), // "appendBlue"
QT_MOC_LITERAL(11, 119, 11), // "appendGreen"
QT_MOC_LITERAL(12, 131, 11) // "appendWhite"

    },
    "nmea_parser\0downloadFinished\0\0"
    "pipeParsedData\0data\0SIGNALqueryLocus\0"
    "updateProgressBar\0progress\0appendRed\0"
    "msg\0appendBlue\0appendGreen\0appendWhite"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmea_parser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,
       8,    1,   62,    2, 0x06 /* Public */,
      10,    1,   65,    2, 0x06 /* Public */,
      11,    1,   68,    2, 0x06 /* Public */,
      12,    1,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void nmea_parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nmea_parser *_t = static_cast<nmea_parser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadFinished(); break;
        case 1: _t->pipeParsedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SIGNALqueryLocus(); break;
        case 3: _t->updateProgressBar((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->appendRed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->appendBlue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->appendGreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->appendWhite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (nmea_parser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::downloadFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (nmea_parser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::pipeParsedData)) {
                *result = 1;
            }
        }
        {
            typedef void (nmea_parser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::SIGNALqueryLocus)) {
                *result = 2;
            }
        }
        {
            typedef void (nmea_parser::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::updateProgressBar)) {
                *result = 3;
            }
        }
        {
            typedef void (nmea_parser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::appendRed)) {
                *result = 4;
            }
        }
        {
            typedef void (nmea_parser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::appendBlue)) {
                *result = 5;
            }
        }
        {
            typedef void (nmea_parser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::appendGreen)) {
                *result = 6;
            }
        }
        {
            typedef void (nmea_parser::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nmea_parser::appendWhite)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject nmea_parser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nmea_parser.data,
      qt_meta_data_nmea_parser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nmea_parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmea_parser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nmea_parser.stringdata0))
        return static_cast<void*>(const_cast< nmea_parser*>(this));
    return QObject::qt_metacast(_clname);
}

int nmea_parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void nmea_parser::downloadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void nmea_parser::pipeParsedData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nmea_parser::SIGNALqueryLocus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void nmea_parser::updateProgressBar(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void nmea_parser::appendRed(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void nmea_parser::appendBlue(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void nmea_parser::appendGreen(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void nmea_parser::appendWhite(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
