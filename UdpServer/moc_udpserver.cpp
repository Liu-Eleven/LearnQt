/****************************************************************************
** Meta object code from reading C++ file 'udpserver.h'
**
** Created: Sat Feb 11 08:58:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "udpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UdpServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      23,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UdpServer[] = {
    "UdpServer\0\0Mytimeout()\0clickedIsStart()\0"
};

void UdpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UdpServer *_t = static_cast<UdpServer *>(_o);
        switch (_id) {
        case 0: _t->Mytimeout(); break;
        case 1: _t->clickedIsStart(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData UdpServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UdpServer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UdpServer,
      qt_meta_data_UdpServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UdpServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UdpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UdpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UdpServer))
        return static_cast<void*>(const_cast< UdpServer*>(this));
    return QDialog::qt_metacast(_clname);
}

int UdpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
