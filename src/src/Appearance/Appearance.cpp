#include "Appearance.hpp"
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QStringList>
#include <algorithm>
#include <QColor>
#include <QDebug>
#include "../Functions/ColorUtils.hpp"

ColorsGroup::ColorsGroup(M3Colors *m3, QObject *parent)
    : QObject(parent), m_m3(m3)
{
    recompute(0, 0, false);
}

void ColorsGroup::recompute(qreal backgroundTransparency, qreal contentTransparency, bool extraBackgroundTint)
{
    QColor new_colSubtext = m_m3->m3outline();
    if (m_colSubtext != new_colSubtext) {
        m_colSubtext = new_colSubtext;
        emit colSubtextChanged();
    }

    QColor new_colLayer0 = ColorUtils::mix(
        ColorUtils::transparentize(m_m3->m3background(), backgroundTransparency),
        m_m3->m3primary(),
        extraBackgroundTint ? 0.99 : 1.0);
    if (m_colLayer0 != new_colLayer0) {
        m_colLayer0 = new_colLayer0;
        emit colLayer0Changed();
    }
    QColor new_colOnLayer0 = m_m3->m3onBackground();
    if (m_colOnLayer0 != new_colOnLayer0) {
        m_colOnLayer0 = new_colOnLayer0;
        emit colOnLayer0Changed();
    }
    QColor new_colLayer0Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer0, m_colOnLayer0, 0.9), contentTransparency);
    if (m_colLayer0Hover != new_colLayer0Hover) {
        m_colLayer0Hover = new_colLayer0Hover;
        emit colLayer0HoverChanged();
    }
    QColor new_colLayer0Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer0, m_colOnLayer0, 0.8), contentTransparency);
    if (m_colLayer0Active != new_colLayer0Active) {
        m_colLayer0Active = new_colLayer0Active;
        emit colLayer0ActiveChanged();
    }
    QColor new_colLayer0Border = ColorUtils::mix(m_m3->m3outlineVariant(), m_colLayer0, 0.4);
    if (m_colLayer0Border != new_colLayer0Border) {
        m_colLayer0Border = new_colLayer0Border;
        emit colLayer0BorderChanged();
    }

    QColor new_colLayer1 = ColorUtils::transparentize(m_m3->m3surfaceContainerLow(), contentTransparency);
    if (m_colLayer1 != new_colLayer1) {
        m_colLayer1 = new_colLayer1;
        emit colLayer1Changed();
    }
    QColor new_colOnLayer1 = m_m3->m3onSurfaceVariant();
    if (m_colOnLayer1 != new_colOnLayer1) {
        m_colOnLayer1 = new_colOnLayer1;
        emit colOnLayer1Changed();
    }
    QColor new_colOnLayer1Inactive = ColorUtils::mix(m_colOnLayer1, m_colLayer1, 0.45);
    if (m_colOnLayer1Inactive != new_colOnLayer1Inactive) {
        m_colOnLayer1Inactive = new_colOnLayer1Inactive;
        emit colOnLayer1InactiveChanged();
    }

    QColor new_colLayer2 = ColorUtils::transparentize(m_m3->m3surfaceContainer(), contentTransparency);
    if (m_colLayer2 != new_colLayer2) {
        m_colLayer2 = new_colLayer2;
        emit colLayer2Changed();
    }
    QColor new_colOnLayer2 = m_m3->m3onSurface();
    if (m_colOnLayer2 != new_colOnLayer2) {
        m_colOnLayer2 = new_colOnLayer2;
        emit colOnLayer2Changed();
    }
    QColor new_colOnLayer2Disabled = ColorUtils::mix(m_colOnLayer2, m_m3->m3background(), 0.4);
    if (m_colOnLayer2Disabled != new_colOnLayer2Disabled) {
        m_colOnLayer2Disabled = new_colOnLayer2Disabled;
        emit colOnLayer2DisabledChanged();
    }

    QColor new_colLayer1Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer1, m_colOnLayer1, 0.92), contentTransparency);
    if (m_colLayer1Hover != new_colLayer1Hover) {
        m_colLayer1Hover = new_colLayer1Hover;
        emit colLayer1HoverChanged();
    }
    QColor new_colLayer1Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer1, m_colOnLayer1, 0.85), contentTransparency);
    if (m_colLayer1Active != new_colLayer1Active) {
        m_colLayer1Active = new_colLayer1Active;
        emit colLayer1ActiveChanged();
    }
    QColor new_colLayer2Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_colOnLayer2, 0.90), contentTransparency);
    if (m_colLayer2Hover != new_colLayer2Hover) {
        m_colLayer2Hover = new_colLayer2Hover;
        emit colLayer2HoverChanged();
    }
    QColor new_colLayer2Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_colOnLayer2, 0.80), contentTransparency);
    if (m_colLayer2Active != new_colLayer2Active) {
        m_colLayer2Active = new_colLayer2Active;
        emit colLayer2ActiveChanged();
    }
    QColor new_colLayer2Disabled = ColorUtils::transparentize(ColorUtils::mix(m_colLayer2, m_m3->m3background(), 0.8), contentTransparency);
    if (m_colLayer2Disabled != new_colLayer2Disabled) {
        m_colLayer2Disabled = new_colLayer2Disabled;
        emit colLayer2DisabledChanged();
    }

    QColor new_colLayer3 = ColorUtils::transparentize(m_m3->m3surfaceContainerHigh(), contentTransparency);
    if (m_colLayer3 != new_colLayer3) {
        m_colLayer3 = new_colLayer3;
        emit colLayer3Changed();
    }
    QColor new_colOnLayer3 = m_m3->m3onSurface();
    if (m_colOnLayer3 != new_colOnLayer3) {
        m_colOnLayer3 = new_colOnLayer3;
        emit colOnLayer3Changed();
    }
    QColor new_colLayer3Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer3, m_colOnLayer3, 0.90), contentTransparency);
    if (m_colLayer3Hover != new_colLayer3Hover) {
        m_colLayer3Hover = new_colLayer3Hover;
        emit colLayer3HoverChanged();
    }
    QColor new_colLayer3Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer3, m_colOnLayer3, 0.80), contentTransparency);
    if (m_colLayer3Active != new_colLayer3Active) {
        m_colLayer3Active = new_colLayer3Active;
        emit colLayer3ActiveChanged();
    }

    QColor new_colLayer4 = ColorUtils::transparentize(m_m3->m3surfaceContainerHighest(), contentTransparency);
    if (m_colLayer4 != new_colLayer4) {
        m_colLayer4 = new_colLayer4;
        emit colLayer4Changed();
    }
    QColor new_colOnLayer4 = m_m3->m3onSurface();
    if (m_colOnLayer4 != new_colOnLayer4) {
        m_colOnLayer4 = new_colOnLayer4;
        emit colOnLayer4Changed();
    }
    QColor new_colLayer4Hover = ColorUtils::transparentize(ColorUtils::mix(m_colLayer4, m_colOnLayer4, 0.90), contentTransparency);
    if (m_colLayer4Hover != new_colLayer4Hover) {
        m_colLayer4Hover = new_colLayer4Hover;
        emit colLayer4HoverChanged();
    }
    QColor new_colLayer4Active = ColorUtils::transparentize(ColorUtils::mix(m_colLayer4, m_colOnLayer4, 0.80), contentTransparency);
    if (m_colLayer4Active != new_colLayer4Active) {
        m_colLayer4Active = new_colLayer4Active;
        emit colLayer4ActiveChanged();
    }

    QColor new_colPrimary = m_m3->m3primary();
    if (m_colPrimary != new_colPrimary) {
        m_colPrimary = new_colPrimary;
        emit colPrimaryChanged();
    }
    QColor new_colOnPrimary = m_m3->m3onPrimary();
    if (m_colOnPrimary != new_colOnPrimary) {
        m_colOnPrimary = new_colOnPrimary;
        emit colOnPrimaryChanged();
    }
    QColor new_colPrimaryHover = ColorUtils::mix(m_colPrimary, m_colLayer1Hover, 0.87);
    if (m_colPrimaryHover != new_colPrimaryHover) {
        m_colPrimaryHover = new_colPrimaryHover;
        emit colPrimaryHoverChanged();
    }
    QColor new_colPrimaryActive = ColorUtils::mix(m_colPrimary, m_colLayer1Active, 0.7);
    if (m_colPrimaryActive != new_colPrimaryActive) {
        m_colPrimaryActive = new_colPrimaryActive;
        emit colPrimaryActiveChanged();
    }
    QColor new_colPrimaryContainer = m_m3->m3primaryContainer();
    if (m_colPrimaryContainer != new_colPrimaryContainer) {
        m_colPrimaryContainer = new_colPrimaryContainer;
        emit colPrimaryContainerChanged();
    }
    QColor new_colOnPrimaryContainer = m_m3->m3onPrimaryContainer();
    if (m_colOnPrimaryContainer != new_colOnPrimaryContainer) {
        m_colOnPrimaryContainer = new_colOnPrimaryContainer;
        emit colOnPrimaryContainerChanged();
    }
    QColor new_colPrimaryContainerHover = ColorUtils::mix(m_colPrimaryContainer, m_colOnPrimaryContainer, 0.9);
    if (m_colPrimaryContainerHover != new_colPrimaryContainerHover) {
        m_colPrimaryContainerHover = new_colPrimaryContainerHover;
        emit colPrimaryContainerHoverChanged();
    }
    QColor new_colPrimaryContainerActive = ColorUtils::mix(m_colPrimaryContainer, m_colOnPrimaryContainer, 0.8);
    if (m_colPrimaryContainerActive != new_colPrimaryContainerActive) {
        m_colPrimaryContainerActive = new_colPrimaryContainerActive;
        emit colPrimaryContainerActiveChanged();
    }

    QColor new_colSecondary = m_m3->m3secondary();
    if (m_colSecondary != new_colSecondary) {
        m_colSecondary = new_colSecondary;
        emit colSecondaryChanged();
    }
    QColor new_colSecondaryHover = ColorUtils::mix(m_m3->m3secondary(), m_colLayer1Hover, 0.85);
    if (m_colSecondaryHover != new_colSecondaryHover) {
        m_colSecondaryHover = new_colSecondaryHover;
        emit colSecondaryHoverChanged();
    }
    QColor new_colSecondaryActive = ColorUtils::mix(m_m3->m3secondary(), m_colLayer1Active, 0.4);
    if (m_colSecondaryActive != new_colSecondaryActive) {
        m_colSecondaryActive = new_colSecondaryActive;
        emit colSecondaryActiveChanged();
    }
    QColor new_colSecondaryContainer = m_m3->m3secondaryContainer();
    if (m_colSecondaryContainer != new_colSecondaryContainer) {
        m_colSecondaryContainer = new_colSecondaryContainer;
        emit colSecondaryContainerChanged();
    }
    QColor new_colSecondaryContainerHover = ColorUtils::mix(m_m3->m3secondaryContainer(), m_m3->m3onSecondaryContainer(), 0.90);
    if (m_colSecondaryContainerHover != new_colSecondaryContainerHover) {
        m_colSecondaryContainerHover = new_colSecondaryContainerHover;
        emit colSecondaryContainerHoverChanged();
    }
    QColor new_colSecondaryContainerActive = ColorUtils::mix(m_m3->m3secondaryContainer(), m_m3->m3onSecondaryContainer(), 0.54);
    if (m_colSecondaryContainerActive != new_colSecondaryContainerActive) {
        m_colSecondaryContainerActive = new_colSecondaryContainerActive;
        emit colSecondaryContainerActiveChanged();
    }
    QColor new_colOnSecondaryContainer = m_m3->m3onSecondaryContainer();
    if (m_colOnSecondaryContainer != new_colOnSecondaryContainer) {
        m_colOnSecondaryContainer = new_colOnSecondaryContainer;
        emit colOnSecondaryContainerChanged();
    }

    QColor new_colTertiary = m_m3->m3tertiary();
    if (m_colTertiary != new_colTertiary) {
        m_colTertiary = new_colTertiary;
        emit colTertiaryChanged();
    }
    QColor new_colTertiaryHover = ColorUtils::mix(m_m3->m3tertiary(), m_colLayer1Hover, 0.85);
    if (m_colTertiaryHover != new_colTertiaryHover) {
        m_colTertiaryHover = new_colTertiaryHover;
        emit colTertiaryHoverChanged();
    }
    QColor new_colTertiaryActive = ColorUtils::mix(m_m3->m3tertiary(), m_colLayer1Active, 0.4);
    if (m_colTertiaryActive != new_colTertiaryActive) {
        m_colTertiaryActive = new_colTertiaryActive;
        emit colTertiaryActiveChanged();
    }
    QColor new_colTertiaryContainer = m_m3->m3tertiaryContainer();
    if (m_colTertiaryContainer != new_colTertiaryContainer) {
        m_colTertiaryContainer = new_colTertiaryContainer;
        emit colTertiaryContainerChanged();
    }
    QColor new_colTertiaryContainerHover = ColorUtils::mix(m_m3->m3tertiaryContainer(), m_m3->m3onTertiaryContainer(), 0.90);
    if (m_colTertiaryContainerHover != new_colTertiaryContainerHover) {
        m_colTertiaryContainerHover = new_colTertiaryContainerHover;
        emit colTertiaryContainerHoverChanged();
    }
    QColor new_colTertiaryContainerActive = ColorUtils::mix(m_m3->m3tertiaryContainer(), m_colLayer1Active, 0.54);
    if (m_colTertiaryContainerActive != new_colTertiaryContainerActive) {
        m_colTertiaryContainerActive = new_colTertiaryContainerActive;
        emit colTertiaryContainerActiveChanged();
    }

    QColor new_colSurfaceContainerLow = ColorUtils::transparentize(m_m3->m3surfaceContainerLow(), contentTransparency);
    if (m_colSurfaceContainerLow != new_colSurfaceContainerLow) {
        m_colSurfaceContainerLow = new_colSurfaceContainerLow;
        emit colSurfaceContainerLowChanged();
    }
    QColor new_colSurfaceContainer = ColorUtils::transparentize(m_m3->m3surfaceContainer(), contentTransparency);
    if (m_colSurfaceContainer != new_colSurfaceContainer) {
        m_colSurfaceContainer = new_colSurfaceContainer;
        emit colSurfaceContainerChanged();
    }
    QColor new_colSurfaceContainerHigh = ColorUtils::transparentize(m_m3->m3surfaceContainerHigh(), contentTransparency);
    if (m_colSurfaceContainerHigh != new_colSurfaceContainerHigh) {
        m_colSurfaceContainerHigh = new_colSurfaceContainerHigh;
        emit colSurfaceContainerHighChanged();
    }
    QColor new_colSurfaceContainerHighest = ColorUtils::transparentize(m_m3->m3surfaceContainerHighest(), contentTransparency);
    if (m_colSurfaceContainerHighest != new_colSurfaceContainerHighest) {
        m_colSurfaceContainerHighest = new_colSurfaceContainerHighest;
        emit colSurfaceContainerHighestChanged();
    }
    QColor new_colSurfaceContainerHighestHover = ColorUtils::mix(m_m3->m3surfaceContainerHighest(), m_m3->m3onSurface(), 0.95);
    if (m_colSurfaceContainerHighestHover != new_colSurfaceContainerHighestHover) {
        m_colSurfaceContainerHighestHover = new_colSurfaceContainerHighestHover;
        emit colSurfaceContainerHighestHoverChanged();
    }
    QColor new_colSurfaceContainerHighestActive = ColorUtils::mix(m_m3->m3surfaceContainerHighest(), m_m3->m3onSurface(), 0.85);
    if (m_colSurfaceContainerHighestActive != new_colSurfaceContainerHighestActive) {
        m_colSurfaceContainerHighestActive = new_colSurfaceContainerHighestActive;
        emit colSurfaceContainerHighestActiveChanged();
    }

    QColor new_colOnSurface = m_m3->m3onSurface();
    if (m_colOnSurface != new_colOnSurface) {
        m_colOnSurface = new_colOnSurface;
        emit colOnSurfaceChanged();
    }
    QColor new_colOnSurfaceVariant = m_m3->m3onSurfaceVariant();
    if (m_colOnSurfaceVariant != new_colOnSurfaceVariant) {
        m_colOnSurfaceVariant = new_colOnSurfaceVariant;
        emit colOnSurfaceVariantChanged();
    }
    QColor new_colTooltip = m_m3->m3inverseSurface();
    if (m_colTooltip != new_colTooltip) {
        m_colTooltip = new_colTooltip;
        emit colTooltipChanged();
    }
    QColor new_colOnTooltip = m_m3->m3inverseOnSurface();
    if (m_colOnTooltip != new_colOnTooltip) {
        m_colOnTooltip = new_colOnTooltip;
        emit colOnTooltipChanged();
    }
    QColor new_colScrim = ColorUtils::transparentize(m_m3->m3scrim(), 0.5);
    if (m_colScrim != new_colScrim) {
        m_colScrim = new_colScrim;
        emit colScrimChanged();
    }
    QColor new_colShadow = ColorUtils::transparentize(m_m3->m3shadow(), 0.7);
    if (m_colShadow != new_colShadow) {
        m_colShadow = new_colShadow;
        emit colShadowChanged();
    }
    QColor new_colOutline = m_m3->m3outline();
    if (m_colOutline != new_colOutline) {
        m_colOutline = new_colOutline;
        emit colOutlineChanged();
    }
    QColor new_colOutlineVariant = m_m3->m3outlineVariant();
    if (m_colOutlineVariant != new_colOutlineVariant) {
        m_colOutlineVariant = new_colOutlineVariant;
        emit colOutlineVariantChanged();
    }

    QColor new_colError = m_m3->m3error();
    if (m_colError != new_colError) {
        m_colError = new_colError;
        emit colErrorChanged();
    }
    QColor new_colErrorHover = ColorUtils::mix(m_m3->m3error(), m_colLayer1Hover, 0.85);
    if (m_colErrorHover != new_colErrorHover) {
        m_colErrorHover = new_colErrorHover;
        emit colErrorHoverChanged();
    }
    QColor new_colErrorActive = ColorUtils::mix(m_m3->m3error(), m_colLayer1Active, 0.7);
    if (m_colErrorActive != new_colErrorActive) {
        m_colErrorActive = new_colErrorActive;
        emit colErrorActiveChanged();
    }
    QColor new_colOnError = m_m3->m3onError();
    if (m_colOnError != new_colOnError) {
        m_colOnError = new_colOnError;
        emit colOnErrorChanged();
    }
    QColor new_colErrorContainer = m_m3->m3errorContainer();
    if (m_colErrorContainer != new_colErrorContainer) {
        m_colErrorContainer = new_colErrorContainer;
        emit colErrorContainerChanged();
    }
    QColor new_colErrorContainerHover = ColorUtils::mix(m_m3->m3errorContainer(), m_m3->m3onErrorContainer(), 0.90);
    if (m_colErrorContainerHover != new_colErrorContainerHover) {
        m_colErrorContainerHover = new_colErrorContainerHover;
        emit colErrorContainerHoverChanged();
    }
    QColor new_colErrorContainerActive = ColorUtils::mix(m_m3->m3errorContainer(), m_m3->m3onErrorContainer(), 0.70);
    if (m_colErrorContainerActive != new_colErrorContainerActive) {
        m_colErrorContainerActive = new_colErrorContainerActive;
        emit colErrorContainerActiveChanged();
    }
    QColor new_colOnErrorContainer = m_m3->m3onErrorContainer();
    if (m_colOnErrorContainer != new_colOnErrorContainer) {
        m_colOnErrorContainer = new_colOnErrorContainer;
        emit colOnErrorContainerChanged();
    }

    
    emit colorsChanged();
}

void Appearance::scheduleRecompute()
{
    if (!m_recomputePending) {
        m_recomputePending = true;
        QMetaObject::invokeMethod(this, [this]() {
            m_recomputePending = false;
            m_colors->recompute(m_backgroundTransparency, m_contentTransparency, m_extraBackgroundTint);
        }, Qt::QueuedConnection);
    }
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
        scheduleRecompute();
    });
}

void Appearance::setBackgroundTransparency(qreal v)
{
    if (qFuzzyCompare(m_backgroundTransparency, v)) return;
    m_backgroundTransparency = v;
    emit backgroundTransparencyChanged();
    scheduleRecompute();
}

void Appearance::setContentTransparency(qreal v)
{
    if (qFuzzyCompare(m_contentTransparency, v)) return;
    m_contentTransparency = v;
    emit contentTransparencyChanged();
    scheduleRecompute();
}

void Appearance::setExtraBackgroundTint(bool v)
{
    if (m_extraBackgroundTint == v) return;
    m_extraBackgroundTint = v;
    emit extraBackgroundTintChanged();
    scheduleRecompute();
}