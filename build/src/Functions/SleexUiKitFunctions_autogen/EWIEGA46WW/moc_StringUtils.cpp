/****************************************************************************
** Meta object code from reading C++ file 'StringUtils.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Functions/StringUtils.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StringUtils.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11StringUtilsE_t {};
} // unnamed namespace

template <> constexpr inline auto StringUtils::qt_create_metaobjectdata<qt_meta_tag_ZN11StringUtilsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "StringUtils",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "format",
        "",
        "str",
        "QVariantList",
        "args",
        "getDomain",
        "url",
        "getBaseUrl",
        "shellSingleQuoteEscape",
        "splitMarkdownBlocks",
        "markdown",
        "escapeBackslashes",
        "wordWrap",
        "maxLen",
        "cleanMusicTitle",
        "title",
        "friendlyTimeForSeconds",
        "seconds",
        "escapeHtml",
        "cleanCliphistEntry",
        "stringListContainsSubstring",
        "substrings",
        "cleanPrefix",
        "prefix",
        "cleanOnePrefix",
        "prefixes"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'format'
        QtMocHelpers::MethodData<QString(const QString &, const QVariantList &) const>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Method 'getDomain'
        QtMocHelpers::MethodData<QString(const QString &) const>(10, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'getBaseUrl'
        QtMocHelpers::MethodData<QString(const QString &) const>(12, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'shellSingleQuoteEscape'
        QtMocHelpers::MethodData<QString(const QString &) const>(13, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'splitMarkdownBlocks'
        QtMocHelpers::MethodData<QVariantList(const QString &) const>(14, 6, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 15 },
        }}),
        // Method 'escapeBackslashes'
        QtMocHelpers::MethodData<QString(const QString &) const>(16, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'wordWrap'
        QtMocHelpers::MethodData<QString(const QString &, int) const>(17, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 }, { QMetaType::Int, 18 },
        }}),
        // Method 'cleanMusicTitle'
        QtMocHelpers::MethodData<QString(const QString &) const>(19, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 20 },
        }}),
        // Method 'friendlyTimeForSeconds'
        QtMocHelpers::MethodData<QString(double) const>(21, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::Double, 22 },
        }}),
        // Method 'escapeHtml'
        QtMocHelpers::MethodData<QString(const QString &) const>(23, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'cleanCliphistEntry'
        QtMocHelpers::MethodData<QString(const QString &) const>(24, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'stringListContainsSubstring'
        QtMocHelpers::MethodData<bool(const QString &, const QStringList &) const>(25, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 }, { QMetaType::QStringList, 26 },
        }}),
        // Method 'cleanPrefix'
        QtMocHelpers::MethodData<QString(const QString &, const QString &) const>(27, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 28 },
        }}),
        // Method 'cleanOnePrefix'
        QtMocHelpers::MethodData<QString(const QString &, const QStringList &) const>(29, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 }, { QMetaType::QStringList, 30 },
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
    return QtMocHelpers::metaObjectData<StringUtils, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject StringUtils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StringUtilsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StringUtilsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11StringUtilsE_t>.metaTypes,
    nullptr
} };

void StringUtils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<StringUtils *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->format((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QVariantList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getDomain((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getBaseUrl((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->shellSingleQuoteEscape((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariantList _r = _t->splitMarkdownBlocks((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->escapeBackslashes((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->wordWrap((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->cleanMusicTitle((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->friendlyTimeForSeconds((*reinterpret_cast<std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->escapeHtml((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->cleanCliphistEntry((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->stringListContainsSubstring((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->cleanPrefix((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->cleanOnePrefix((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *StringUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StringUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StringUtilsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StringUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
