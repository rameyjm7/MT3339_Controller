/****************************************************************************
** Meta object code from reading C++ file 'download_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "download_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'download_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_download_dialog_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_download_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_download_dialog_t qt_meta_stringdata_download_dialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "download_dialog"
QT_MOC_LITERAL(1, 16, 11), // "writeSerial"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "a"
QT_MOC_LITERAL(4, 31, 8), // "saveData"
QT_MOC_LITERAL(5, 40, 10), // "appendData"
QT_MOC_LITERAL(6, 51, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 73, 23) // "on_pushButton_2_clicked"

    },
    "download_dialog\0writeSerial\0\0a\0saveData\0"
    "appendData\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_download_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void download_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        download_dialog *_t = static_cast<download_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->saveData(); break;
        case 2: _t->appendData(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject download_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_download_dialog.data,
      qt_meta_data_download_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *download_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *download_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_download_dialog.stringdata0))
        return static_cast<void*>(const_cast< download_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int download_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
