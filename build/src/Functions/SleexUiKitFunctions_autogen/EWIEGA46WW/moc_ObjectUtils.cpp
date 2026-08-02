/****************************************************************************
** Meta object code from reading C++ file 'ObjectUtils.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Functions/ObjectUtils.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjectUtils.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN11ObjectUtilsE_t {};
} // unnamed namespace

template <> constexpr inline auto ObjectUtils::qt_create_metaobjectdata<qt_meta_tag_ZN11ObjectUtilsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ObjectUtils",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toPlainObject",
        "QJSValue",
        "",
        "qtObj",
        "applyToQtObject",
        "jsonObj"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toPlainObject'
        QtMocHelpers::MethodData<QJSValue(QJSValue) const>(5, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 },
        }}),
        // Method 'applyToQtObject'
        QtMocHelpers::MethodData<void(QJSValue, QJSValue) const>(9, 7, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<ObjectUtils, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ObjectUtils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ObjectUtilsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ObjectUtilsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ObjectUtilsE_t>.metaTypes,
    nullptr
} };

void ObjectUtils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ObjectUtils *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QJSValue _r = _t->toPlainObject((*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->applyToQtObject((*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ObjectUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ObjectUtilsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ObjectUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
