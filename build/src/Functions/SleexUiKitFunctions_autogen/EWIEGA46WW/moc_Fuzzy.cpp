/****************************************************************************
** Meta object code from reading C++ file 'Fuzzy.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Functions/Fuzzy.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Fuzzy.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5FuzzyE_t {};
} // unnamed namespace

template <> constexpr inline auto Fuzzy::qt_create_metaobjectdata<qt_meta_tag_ZN5FuzzyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Fuzzy",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "computeScore",
        "",
        "search",
        "target",
        "computeTextMatchScore",
        "prepare",
        "QJSValue",
        "go",
        "targets",
        "options"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'computeScore'
        QtMocHelpers::MethodData<double(const QString &, const QString &) const>(5, 6, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
        // Method 'computeTextMatchScore'
        QtMocHelpers::MethodData<double(const QString &, const QString &) const>(9, 6, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
        // Method 'prepare'
        QtMocHelpers::MethodData<QJSValue(const QJSValue &) const>(10, 6, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 11, 8 },
        }}),
        // Method 'go'
        QtMocHelpers::MethodData<QJSValue(const QString &, const QJSValue &, const QJSValue &) const>(12, 6, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 11, 13 }, { 0x80000000 | 11, 14 },
        }}),
        // Method 'go'
        QtMocHelpers::MethodData<QJSValue(const QString &, const QJSValue &) const>(12, 6, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 11, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 11, 13 },
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
    return QtMocHelpers::metaObjectData<Fuzzy, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Fuzzy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5FuzzyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5FuzzyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5FuzzyE_t>.metaTypes,
    nullptr
} };

void Fuzzy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Fuzzy *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { double _r = _t->computeScore((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<double*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->computeTextMatchScore((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<double*>(_a[0]) = std::move(_r); }  break;
        case 2: { QJSValue _r = _t->prepare((*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 3: { QJSValue _r = _t->go((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QJSValue*>(_a[0]) = std::move(_r); }  break;
        case 4: { QJSValue _r = _t->go((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJSValue>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QJSValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Fuzzy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fuzzy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5FuzzyE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Fuzzy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
