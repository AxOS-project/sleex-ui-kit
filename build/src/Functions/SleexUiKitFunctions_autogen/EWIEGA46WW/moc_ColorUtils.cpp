/****************************************************************************
** Meta object code from reading C++ file 'ColorUtils.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Functions/ColorUtils.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorUtils.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10ColorUtilsE_t {};
} // unnamed namespace

template <> constexpr inline auto ColorUtils::qt_create_metaobjectdata<qt_meta_tag_ZN10ColorUtilsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ColorUtils",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "colorWithHueOf",
        "QColor",
        "",
        "color1",
        "color2",
        "colorWithSaturationOf",
        "colorWithLightness",
        "color",
        "lightness",
        "colorWithLightnessOf",
        "adaptToAccent",
        "mix",
        "percentage",
        "transparentize",
        "applyAlpha",
        "alpha",
        "stringToColor",
        "str",
        "getContrastingTextColor",
        "bgColor"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'colorWithHueOf'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &)>(5, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 },
        }}),
        // Method 'colorWithSaturationOf'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &)>(10, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 },
        }}),
        // Method 'colorWithLightness'
        QtMocHelpers::MethodData<QColor(const QColor &, qreal)>(11, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 12 }, { QMetaType::QReal, 13 },
        }}),
        // Method 'colorWithLightnessOf'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &)>(14, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 },
        }}),
        // Method 'adaptToAccent'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &)>(15, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 },
        }}),
        // Method 'mix'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &, qreal)>(16, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 }, { QMetaType::QReal, 17 },
        }}),
        // Method 'mix'
        QtMocHelpers::MethodData<QColor(const QColor &, const QColor &)>(16, 7, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 6, {{
            { 0x80000000 | 6, 8 }, { 0x80000000 | 6, 9 },
        }}),
        // Method 'transparentize'
        QtMocHelpers::MethodData<QColor(const QColor &, qreal)>(18, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 12 }, { QMetaType::QReal, 17 },
        }}),
        // Method 'transparentize'
        QtMocHelpers::MethodData<QColor(const QColor &)>(18, 7, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 6, {{
            { 0x80000000 | 6, 12 },
        }}),
        // Method 'applyAlpha'
        QtMocHelpers::MethodData<QColor(const QColor &, qreal)>(19, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 6, 12 }, { QMetaType::QReal, 20 },
        }}),
        // Method 'stringToColor'
        QtMocHelpers::MethodData<QString(const QString &)>(21, 7, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 22 },
        }}),
        // Method 'getContrastingTextColor'
        QtMocHelpers::MethodData<QString(const QColor &)>(23, 7, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 6, 24 },
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
    return QtMocHelpers::metaObjectData<ColorUtils, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ColorUtils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ColorUtilsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ColorUtilsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10ColorUtilsE_t>.metaTypes,
    nullptr
} };

void ColorUtils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ColorUtils *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QColor _r = _t->colorWithHueOf((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 1: { QColor _r = _t->colorWithSaturationOf((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 2: { QColor _r = _t->colorWithLightness((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 3: { QColor _r = _t->colorWithLightnessOf((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 4: { QColor _r = _t->adaptToAccent((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 5: { QColor _r = _t->mix((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 6: { QColor _r = _t->mix((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 7: { QColor _r = _t->transparentize((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 8: { QColor _r = _t->transparentize((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 9: { QColor _r = _t->applyAlpha((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QColor*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->stringToColor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getContrastingTextColor((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *ColorUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10ColorUtilsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ColorUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
