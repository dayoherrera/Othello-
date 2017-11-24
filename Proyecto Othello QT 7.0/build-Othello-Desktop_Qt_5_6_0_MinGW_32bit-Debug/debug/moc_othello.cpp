/****************************************************************************
** Meta object code from reading C++ file 'othello.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Othello/othello.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'othello.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Othello_t {
    QByteArrayData data[13];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Othello_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Othello_t qt_meta_stringdata_Othello = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Othello"
QT_MOC_LITERAL(1, 8, 20), // "onGroupButtonClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "id"
QT_MOC_LITERAL(4, 33, 21), // "on_BotonNuevo_clicked"
QT_MOC_LITERAL(5, 55, 18), // "on_ganador_clicked"
QT_MOC_LITERAL(6, 74, 19), // "on_jugvsjug_clicked"
QT_MOC_LITERAL(7, 94, 19), // "on_jugvscom_clicked"
QT_MOC_LITERAL(8, 114, 16), // "on_Ayuda_clicked"
QT_MOC_LITERAL(9, 131, 19), // "on_Creditos_clicked"
QT_MOC_LITERAL(10, 151, 20), // "on_BotonSuge_clicked"
QT_MOC_LITERAL(11, 172, 16), // "on_facil_clicked"
QT_MOC_LITERAL(12, 189, 18) // "on_dificil_clicked"

    },
    "Othello\0onGroupButtonClicked\0\0id\0"
    "on_BotonNuevo_clicked\0on_ganador_clicked\0"
    "on_jugvsjug_clicked\0on_jugvscom_clicked\0"
    "on_Ayuda_clicked\0on_Creditos_clicked\0"
    "on_BotonSuge_clicked\0on_facil_clicked\0"
    "on_dificil_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Othello[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
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

void Othello::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Othello *_t = static_cast<Othello *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGroupButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_BotonNuevo_clicked(); break;
        case 2: _t->on_ganador_clicked(); break;
        case 3: _t->on_jugvsjug_clicked(); break;
        case 4: _t->on_jugvscom_clicked(); break;
        case 5: _t->on_Ayuda_clicked(); break;
        case 6: _t->on_Creditos_clicked(); break;
        case 7: _t->on_BotonSuge_clicked(); break;
        case 8: _t->on_facil_clicked(); break;
        case 9: _t->on_dificil_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Othello::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Othello.data,
      qt_meta_data_Othello,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Othello::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Othello::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Othello.stringdata0))
        return static_cast<void*>(const_cast< Othello*>(this));
    return QWidget::qt_metacast(_clname);
}

int Othello::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
