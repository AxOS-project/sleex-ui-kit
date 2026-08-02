#include "Appearance.hpp"
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QStringList>
#include <algorithm>
#include <QColor>
#include <QDebug>
#include "../Functions/ColorUtils.hpp"

static QString bezierToString(const QVector<qreal> &curve) {
    if (curve.isEmpty()) return QString();
    QStringList items;
    for (qreal val : curve) {
        items << QString::number(val);
    }
    return QString("[%1]").arg(items.join(", "));
}

static QString easingTypeToString(int type) {
    if (type == 26) return "Easing.BezierSpline";
    if (type == 8) return "Easing.OutExpo";
    return "Easing.Linear";
}

static QQmlEngine *findEngine(QObject *obj) {
    if (!obj) return nullptr;
    if (QQmlEngine *eng = qmlEngine(obj)) return eng;
    if (QQmlContext *ctx = qmlContext(obj)) return ctx->engine();
    return findEngine(obj->parent());
}

QQmlComponent *AnimationSpec::numberAnimation() {
    if (!m_numberAnimation) {
        QQmlEngine *engine = findEngine(this);
        if (engine) {
            m_numberAnimation = new QQmlComponent(engine, this);
            QString qml = QString("import QtQuick\nNumberAnimation {\n duration: %1\n easing.type: %2%3\n}")
                .arg(m_duration)
                .arg(easingTypeToString(m_type))
                .arg(m_bezierCurve.isEmpty() ? QString() : QString("\n easing.bezierCurve: %1").arg(bezierToString(m_bezierCurve)));
            m_numberAnimation->setData(qml.toUtf8(), QUrl("file:///AnimationSpecNumber.qml"));
            if (m_numberAnimation->isError()) {
                qWarning() << "AnimationSpec numberAnimation error:" << m_numberAnimation->errorString();
            }
        }
    }
    return m_numberAnimation;
}

QQmlComponent *AnimationSpec::colorAnimation() {
    if (!m_colorAnimation) {
        QQmlEngine *engine = findEngine(this);
        if (engine) {
            m_colorAnimation = new QQmlComponent(engine, this);
            QString qml = QString("import QtQuick\nColorAnimation {\n duration: %1\n easing.type: %2%3\n}")
                .arg(m_duration)
                .arg(easingTypeToString(m_type))
                .arg(m_bezierCurve.isEmpty() ? QString() : QString("\n easing.bezierCurve: %1").arg(bezierToString(m_bezierCurve)));
            m_colorAnimation->setData(qml.toUtf8(), QUrl("file:///AnimationSpecColor.qml"));
            if (m_colorAnimation->isError()) {
                qWarning() << "AnimationSpec colorAnimation error:" << m_colorAnimation->errorString();
            }
        }
    }
    return m_colorAnimation;
}

ColorsGroup::ColorsGroup(M3Colors *m3, QObject *parent)
    : QObject(parent), m_m3(m3)
{
    recompute(0, 0, false);
}

void ColorsGroup::recompute(qreal backgroundTransparency, qreal contentTransparency, bool extraBackgroundTint)
{
    m_colSubtext = m_m3->m3outline();

    m_colLayer0 = ColorUtils::mix(
        ColorUtils::transparentize(m_m3->m3background(), backgroundTransparency),
        m_m3->m3primary(),
        extraBackgroundTint ? 0.99 : 1.0);
    m_colOnLayer0 = m_m3->m3onBackground();
    m_colLayer0Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer0, m_colOnLayer0, 0.9), contentTransparency);
    m_colLayer0Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer0, m_colOnLayer0, 0.8), contentTransparency);
    m_colLayer0Border = ColorUtils::mix(m_m3->m3outlineVariant(), m_colLayer0, 0.4);

    m_colLayer1 = ColorUtils::transparentize(m_m3->m3surfaceContainerLow(), contentTransparency);
    m_colOnLayer1 = m_m3->m3onSurfaceVariant();
    m_colOnLayer1Inactive = ColorUtils::mix(m_colOnLayer1, m_colLayer1, 0.45);

    m_colLayer2 = ColorUtils::transparentize(m_m3->m3surfaceContainer(), contentTransparency);
    m_colOnLayer2 = m_m3->m3onSurface();
    m_colOnLayer2Disabled = ColorUtils::mix(m_colOnLayer2, m_m3->m3background(), 0.4);

    m_colLayer1Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer1, m_colOnLayer1, 0.92), contentTransparency);
    m_colLayer1Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer1, m_colOnLayer1, 0.85), contentTransparency);
    m_colLayer2Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_colOnLayer2, 0.90), contentTransparency);
    m_colLayer2Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_colOnLayer2, 0.80), contentTransparency);
    m_colLayer2Disabled = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_m3->m3background(), 0.8), contentTransparency);

    m_colLayer3 = ColorUtils::transparentize(m_m3->m3surfaceContainerHigh(), contentTransparency);
    m_colOnLayer3 = m_m3->m3onSurface();
    m_colLayer3Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer3, m_colOnLayer3, 0.90), contentTransparency);
    m_colLayer3Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer3, m_colOnLayer3, 0.80), contentTransparency);

    m_colLayer4 = ColorUtils::transparentize(m_m3->m3surfaceContainerHighest(), contentTransparency);
    m_colOnLayer4 = m_m3->m3onSurface();
    m_colLayer4Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer4, m_colOnLayer4, 0.90), contentTransparency);
    m_colLayer4Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer4, m_colOnLayer4, 0.80), contentTransparency);

    m_colPrimary = m_m3->m3primary();
    m_colOnPrimary = m_m3->m3onPrimary();
    m_colPrimaryHover = ColorUtils::mix(m_colPrimary, m_colLayer1Hover, 0.87);
    m_colPrimaryActive = ColorUtils::mix(m_colPrimary, m_colLayer1Active, 0.7);
    m_colPrimaryContainer = m_m3->m3primaryContainer();
    m_colOnPrimaryContainer = m_m3->m3onPrimaryContainer();
    m_colPrimaryContainerHover = ColorUtils::mix(m_colPrimaryContainer, m_colOnPrimaryContainer, 0.9);
    m_colPrimaryContainerActive = ColorUtils::mix(m_colPrimaryContainer, m_colOnPrimaryContainer, 0.8);

    m_colSecondary = m_m3->m3secondary();
    m_colSecondaryHover = ColorUtils::mix(m_m3->m3secondary(), m_colLayer1Hover, 0.85);
    m_colSecondaryActive = ColorUtils::mix(m_m3->m3secondary(), m_colLayer1Active, 0.4);
    m_colSecondaryContainer = m_m3->m3secondaryContainer();
    m_colSecondaryContainerHover = ColorUtils::mix(m_m3->m3secondaryContainer(), m_m3->m3onSecondaryContainer(), 0.90);
    m_colSecondaryContainerActive = ColorUtils::mix(m_m3->m3secondaryContainer(), m_m3->m3onSecondaryContainer(), 0.54);
    m_colOnSecondaryContainer = m_m3->m3onSecondaryContainer();

    m_colTertiary = m_m3->m3tertiary();
    m_colTertiaryHover = ColorUtils::mix(m_m3->m3tertiary(), m_colLayer1Hover, 0.85);
    m_colTertiaryActive = ColorUtils::mix(m_m3->m3tertiary(), m_colLayer1Active, 0.4);
    m_colTertiaryContainer = m_m3->m3tertiaryContainer();
    m_colTertiaryContainerHover = ColorUtils::mix(m_m3->m3tertiaryContainer(), m_m3->m3onTertiaryContainer(), 0.90);
    m_colTertiaryContainerActive = ColorUtils::mix(m_m3->m3tertiaryContainer(), m_colLayer1Active, 0.54);

    m_colSurfaceContainerLow = ColorUtils::transparentize(m_m3->m3surfaceContainerLow(), contentTransparency);
    m_colSurfaceContainer = ColorUtils::transparentize(m_m3->m3surfaceContainer(), contentTransparency);
    m_colSurfaceContainerHigh = ColorUtils::transparentize(m_m3->m3surfaceContainerHigh(), contentTransparency);
    m_colSurfaceContainerHighest = ColorUtils::transparentize(m_m3->m3surfaceContainerHighest(), contentTransparency);
    m_colSurfaceContainerHighestHover = ColorUtils::mix(m_m3->m3surfaceContainerHighest(), m_m3->m3onSurface(), 0.95);
    m_colSurfaceContainerHighestActive = ColorUtils::mix(m_m3->m3surfaceContainerHighest(), m_m3->m3onSurface(), 0.85);

    m_colOnSurface = m_m3->m3onSurface();
    m_colOnSurfaceVariant = m_m3->m3onSurfaceVariant();
    m_colTooltip = m_m3->m3inverseSurface();
    m_colOnTooltip = m_m3->m3inverseOnSurface();
    m_colScrim = ColorUtils::transparentize(m_m3->m3scrim(), 0.5);
    m_colShadow = ColorUtils::transparentize(m_m3->m3shadow(), 0.7);
    m_colOutline = m_m3->m3outline();
    m_colOutlineVariant = m_m3->m3outlineVariant();

    m_colError = m_m3->m3error();
    m_colErrorHover = ColorUtils::mix(m_m3->m3error(), m_colLayer1Hover, 0.85);
    m_colErrorActive = ColorUtils::mix(m_m3->m3error(), m_colLayer1Active, 0.7);
    m_colOnError = m_m3->m3onError();
    m_colErrorContainer = m_m3->m3errorContainer();
    m_colErrorContainerHover = ColorUtils::mix(m_m3->m3errorContainer(), m_m3->m3onErrorContainer(), 0.90);
    m_colErrorContainerActive = ColorUtils::mix(m_m3->m3errorContainer(), m_m3->m3onErrorContainer(), 0.70);
    m_colOnErrorContainer = m_m3->m3onErrorContainer();

    emit colorsChanged();
}

Appearance::Appearance(QObject *parent)
    : QObject(parent)
{
    m_m3colors = new M3Colors(this);
    m_colors = new ColorsGroup(m_m3colors, this);
    m_rounding = new RoundingGroup(this);
    m_font = new FontGroup(this);
    m_animationCurves = new AnimationCurvesGroup(this);
    m_animation = new AnimationGroup(m_animationCurves, this);
    m_sizes = new SizesGroup(this);

    connect(m_m3colors, &M3Colors::m3colorsChanged, this, [this]() {
        m_colors->recompute(m_backgroundTransparency, m_contentTransparency, m_extraBackgroundTint);
    });
}

void Appearance::setBackgroundTransparency(qreal v)
{
    if (qFuzzyCompare(m_backgroundTransparency, v)) return;
    m_backgroundTransparency = v;
    emit backgroundTransparencyChanged();
    static_cast<ColorsGroup*>(m_colors)->recompute(m_backgroundTransparency, m_contentTransparency, m_extraBackgroundTint);
}

void Appearance::setContentTransparency(qreal v)
{
    if (qFuzzyCompare(m_contentTransparency, v)) return;
    m_contentTransparency = v;
    emit contentTransparencyChanged();
    static_cast<ColorsGroup*>(m_colors)->recompute(m_backgroundTransparency, m_contentTransparency, m_extraBackgroundTint);
}

void Appearance::setExtraBackgroundTint(bool v)
{
    if (m_extraBackgroundTint == v) return;
    m_extraBackgroundTint = v;
    emit extraBackgroundTintChanged();
    static_cast<ColorsGroup*>(m_colors)->recompute(m_backgroundTransparency, m_contentTransparency, m_extraBackgroundTint);
}