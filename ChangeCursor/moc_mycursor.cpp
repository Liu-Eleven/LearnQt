/****************************************************************************
** Meta object code from reading C++ file 'mycursor.h'
**
** Created: Fri Feb 10 09:34:10 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mycursor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycursor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyCursor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      23,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      51,    9,    9,    9, 0x08,
      65,    9,    9,    9, 0x08,
      79,    9,    9,    9, 0x08,
      92,    9,    9,    9, 0x08,
     107,    9,    9,    9, 0x08,
     122,    9,    9,    9, 0x08,
     136,    9,    9,    9, 0x08,
     149,    9,    9,    9, 0x08,
     165,    9,    9,    9, 0x08,
     181,    9,    9,    9, 0x08,
     199,    9,    9,    9, 0x08,
     217,    9,    9,    9, 0x08,
     234,    9,    9,    9, 0x08,
     251,    9,    9,    9, 0x08,
     270,    9,    9,    9, 0x08,
     288,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyCursor[] = {
    "MyCursor\0\0SetOneCurs()\0SetTwoCurs()\0"
    "SetThreeCurs()\0SetFourCurs()\0SetFiveCurs()\0"
    "SetSixCurs()\0SetSevenCurs()\0SetEightCurs()\0"
    "SetNineCurs()\0SetTenCurs()\0SetElevenCurs()\0"
    "SetTwelveCurs()\0SetThirteenCurs()\0"
    "SetFourteenCurs()\0SetFifteenCurs()\0"
    "SetSixteenCurs()\0SetSeventeenCurs()\0"
    "SetEighteenCurs()\0SetNineteenCurs()\0"
};

void MyCursor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyCursor *_t = static_cast<MyCursor *>(_o);
        switch (_id) {
        case 0: _t->SetOneCurs(); break;
        case 1: _t->SetTwoCurs(); break;
        case 2: _t->SetThreeCurs(); break;
        case 3: _t->SetFourCurs(); break;
        case 4: _t->SetFiveCurs(); break;
        case 5: _t->SetSixCurs(); break;
        case 6: _t->SetSevenCurs(); break;
        case 7: _t->SetEightCurs(); break;
        case 8: _t->SetNineCurs(); break;
        case 9: _t->SetTenCurs(); break;
        case 10: _t->SetElevenCurs(); break;
        case 11: _t->SetTwelveCurs(); break;
        case 12: _t->SetThirteenCurs(); break;
        case 13: _t->SetFourteenCurs(); break;
        case 14: _t->SetFifteenCurs(); break;
        case 15: _t->SetSixteenCurs(); break;
        case 16: _t->SetSeventeenCurs(); break;
        case 17: _t->SetEighteenCurs(); break;
        case 18: _t->SetNineteenCurs(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyCursor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyCursor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyCursor,
      qt_meta_data_MyCursor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyCursor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyCursor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyCursor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyCursor))
        return static_cast<void*>(const_cast< MyCursor*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyCursor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
