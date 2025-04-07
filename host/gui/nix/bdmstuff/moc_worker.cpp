/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "worker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN6WorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto Worker::qt_create_metaobjectdata<qt_meta_tag_ZN6WorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Worker",
        "finished",
        "",
        "WrkMsg_emit",
        "msg",
        "WrkProg_emit",
        "prog",
        "WrkMsg_push",
        "WrkProg_push",
        "FlashEepromProcess",
        "DumpEepromProcess",
        "DumpProcess",
        "FlashProcess",
        "WorkerDone"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'WrkMsg_emit'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'WrkProg_emit'
        QtMocHelpers::SignalData<void(uint)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 6 },
        }}),
        // Slot 'WrkMsg_push'
        QtMocHelpers::SlotData<void(QString)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'WrkProg_push'
        QtMocHelpers::SlotData<void(uint)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::UInt, 6 },
        }}),
        // Slot 'FlashEepromProcess'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'DumpEepromProcess'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'DumpProcess'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'FlashProcess'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'WorkerDone'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Worker, qt_meta_tag_ZN6WorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6WorkerE_t>.metaTypes,
    nullptr
} };

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Worker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->WrkMsg_emit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->WrkProg_emit((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 3: _t->WrkMsg_push((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->WrkProg_push((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 5: _t->FlashEepromProcess(); break;
        case 6: _t->DumpEepromProcess(); break;
        case 7: _t->DumpProcess(); break;
        case 8: _t->FlashProcess(); break;
        case 9: _t->WorkerDone(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Worker::*)()>(_a, &Worker::finished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Worker::*)(QString )>(_a, &Worker::WrkMsg_emit, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Worker::*)(uint )>(_a, &Worker::WrkProg_emit, 2))
            return;
    }
}

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Worker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Worker::WrkMsg_emit(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Worker::WrkProg_emit(uint _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
