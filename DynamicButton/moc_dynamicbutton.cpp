/****************************************************************************
** Meta object code from reading C++ file 'dynamicbutton.h'
**
** Created: Sat Feb 11 09:38:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dynamicbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dynamicbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DynamicButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   20,   15,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DynamicButton[] = {
    "DynamicButton\0\0bool\0,\0"
    "eventFilter(QObject*,QEvent*)\0"
};

void DynamicButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DynamicButton *_t = static_cast<DynamicButton *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DynamicButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DynamicButton::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DynamicButton,
      qt_meta_data_DynamicButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DynamicButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DynamicButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DynamicButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DynamicButton))
        return static_cast<void*>(const_cast< DynamicButton*>(this));
    return QDialog::qt_metacast(_clname);
}

int DynamicButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
