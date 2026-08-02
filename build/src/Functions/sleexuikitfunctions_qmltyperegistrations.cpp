/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<ColorUtils.hpp>)
#  include <ColorUtils.hpp>
#endif
#if __has_include(<DesktopUtils.hpp>)
#  include <DesktopUtils.hpp>
#endif
#if __has_include(<FileUtils.hpp>)
#  include <FileUtils.hpp>
#endif
#if __has_include(<Fuzzy.hpp>)
#  include <Fuzzy.hpp>
#endif
#if __has_include(<Lavendist.hpp>)
#  include <Lavendist.hpp>
#endif
#if __has_include(<ObjectUtils.hpp>)
#  include <ObjectUtils.hpp>
#endif
#if __has_include(<StringUtils.hpp>)
#  include <StringUtils.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_SleexUiKit_Functions()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<ColorUtils>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<DesktopUtils>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<FileUtils>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<Fuzzy>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<Levendist>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<ObjectUtils>("SleexUiKit.Functions", 1);
    qmlRegisterTypesAndRevisions<StringUtils>("SleexUiKit.Functions", 1);
    QT_WARNING_POP
    qmlRegisterModule("SleexUiKit.Functions", 1, 0);
}

static const QQmlModuleRegistration sleexUiKitFunctionsRegistration("SleexUiKit.Functions", qml_register_types_SleexUiKit_Functions);
