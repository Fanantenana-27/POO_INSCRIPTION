/****************************************************************************
** Meta object code from reading C++ file 'inscription.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inscription.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inscription.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Inscription_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Inscription_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Inscription_t qt_meta_stringdata_Inscription = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Inscription"
QT_MOC_LITERAL(1, 12, 8), // "inscrire"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "desabonne"
QT_MOC_LITERAL(4, 32, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 49, 4), // "item"
QT_MOC_LITERAL(6, 54, 8), // "modifier"
QT_MOC_LITERAL(7, 63, 6), // "lister"
QT_MOC_LITERAL(8, 70, 11), // "std::string"
QT_MOC_LITERAL(9, 82, 7), // "fichier"
QT_MOC_LITERAL(10, 90, 11) // "enregistrer"

    },
    "Inscription\0inscrire\0\0desabonne\0"
    "QListWidgetItem*\0item\0modifier\0lister\0"
    "std::string\0fichier\0enregistrer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Inscription[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void Inscription::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Inscription *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inscrire(); break;
        case 1: _t->desabonne((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->modifier((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->lister((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->enregistrer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Inscription::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Inscription.data,
    qt_meta_data_Inscription,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Inscription::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Inscription::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Inscription.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Inscription::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
