#pragma once

#include <QObject>
#include <QColor>
#include <QVector>
#include <QString>
#include <qqml.h>
#include <QtQml/qqmlregistration.h>
#include <QQmlComponent>

class M3Colors : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool darkmode READ darkmode WRITE setDarkmode NOTIFY m3colorsChanged)
    Q_PROPERTY(bool transparent READ transparent WRITE setTransparent NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3background READ m3background WRITE setM3background NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onBackground READ m3onBackground WRITE setM3onBackground NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surface READ m3surface WRITE setM3surface NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceDim READ m3surfaceDim WRITE setM3surfaceDim NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceBright READ m3surfaceBright WRITE setM3surfaceBright NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceContainerLowest READ m3surfaceContainerLowest WRITE setM3surfaceContainerLowest NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceContainerLow READ m3surfaceContainerLow WRITE setM3surfaceContainerLow NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceContainer READ m3surfaceContainer WRITE setM3surfaceContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceContainerHigh READ m3surfaceContainerHigh WRITE setM3surfaceContainerHigh NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceContainerHighest READ m3surfaceContainerHighest WRITE setM3surfaceContainerHighest NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onSurface READ m3onSurface WRITE setM3onSurface NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3surfaceVariant READ m3surfaceVariant WRITE setM3surfaceVariant NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onSurfaceVariant READ m3onSurfaceVariant WRITE setM3onSurfaceVariant NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3inverseSurface READ m3inverseSurface WRITE setM3inverseSurface NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3inverseOnSurface READ m3inverseOnSurface WRITE setM3inverseOnSurface NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3outline READ m3outline WRITE setM3outline NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3outlineVariant READ m3outlineVariant WRITE setM3outlineVariant NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3shadow READ m3shadow WRITE setM3shadow NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3scrim READ m3scrim WRITE setM3scrim NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3primary READ m3primary WRITE setM3primary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onPrimary READ m3onPrimary WRITE setM3onPrimary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3primaryContainer READ m3primaryContainer WRITE setM3primaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onPrimaryContainer READ m3onPrimaryContainer WRITE setM3onPrimaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3secondary READ m3secondary WRITE setM3secondary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onSecondary READ m3onSecondary WRITE setM3onSecondary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3secondaryContainer READ m3secondaryContainer WRITE setM3secondaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onSecondaryContainer READ m3onSecondaryContainer WRITE setM3onSecondaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3tertiary READ m3tertiary WRITE setM3tertiary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onTertiary READ m3onTertiary WRITE setM3onTertiary NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3tertiaryContainer READ m3tertiaryContainer WRITE setM3tertiaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onTertiaryContainer READ m3onTertiaryContainer WRITE setM3onTertiaryContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3error READ m3error WRITE setM3error NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onError READ m3onError WRITE setM3onError NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3errorContainer READ m3errorContainer WRITE setM3errorContainer NOTIFY m3colorsChanged)
    Q_PROPERTY(QColor m3onErrorContainer READ m3onErrorContainer WRITE setM3onErrorContainer NOTIFY m3colorsChanged)

public:
    explicit M3Colors(QObject *parent = nullptr) : QObject(parent) {}

    bool darkmode() const { return m_darkmode; }
    void setDarkmode(bool v) { if (m_darkmode != v) { m_darkmode = v; emit m3colorsChanged(); } }

    bool transparent() const { return m_transparent; }
    void setTransparent(bool v) { if (m_transparent != v) { m_transparent = v; emit m3colorsChanged(); } }

    QColor m3background() const { return m_m3background; }
    void setM3background(const QColor &v) { if (m_m3background != v) { m_m3background = v; emit m3colorsChanged(); } }

    QColor m3onBackground() const { return m_m3onBackground; }
    void setM3onBackground(const QColor &v) { if (m_m3onBackground != v) { m_m3onBackground = v; emit m3colorsChanged(); } }

    QColor m3surface() const { return m_m3surface; }
    void setM3surface(const QColor &v) { if (m_m3surface != v) { m_m3surface = v; emit m3colorsChanged(); } }

    QColor m3surfaceDim() const { return m_m3surfaceDim; }
    void setM3surfaceDim(const QColor &v) { if (m_m3surfaceDim != v) { m_m3surfaceDim = v; emit m3colorsChanged(); } }

    QColor m3surfaceBright() const { return m_m3surfaceBright; }
    void setM3surfaceBright(const QColor &v) { if (m_m3surfaceBright != v) { m_m3surfaceBright = v; emit m3colorsChanged(); } }

    QColor m3surfaceContainerLowest() const { return m_m3surfaceContainerLowest; }
    void setM3surfaceContainerLowest(const QColor &v) { if (m_m3surfaceContainerLowest != v) { m_m3surfaceContainerLowest = v; emit m3colorsChanged(); } }

    QColor m3surfaceContainerLow() const { return m_m3surfaceContainerLow; }
    void setM3surfaceContainerLow(const QColor &v) { if (m_m3surfaceContainerLow != v) { m_m3surfaceContainerLow = v; emit m3colorsChanged(); } }

    QColor m3surfaceContainer() const { return m_m3surfaceContainer; }
    void setM3surfaceContainer(const QColor &v) { if (m_m3surfaceContainer != v) { m_m3surfaceContainer = v; emit m3colorsChanged(); } }

    QColor m3surfaceContainerHigh() const { return m_m3surfaceContainerHigh; }
    void setM3surfaceContainerHigh(const QColor &v) { if (m_m3surfaceContainerHigh != v) { m_m3surfaceContainerHigh = v; emit m3colorsChanged(); } }

    QColor m3surfaceContainerHighest() const { return m_m3surfaceContainerHighest; }
    void setM3surfaceContainerHighest(const QColor &v) { if (m_m3surfaceContainerHighest != v) { m_m3surfaceContainerHighest = v; emit m3colorsChanged(); } }

    QColor m3onSurface() const { return m_m3onSurface; }
    void setM3onSurface(const QColor &v) { if (m_m3onSurface != v) { m_m3onSurface = v; emit m3colorsChanged(); } }

    QColor m3surfaceVariant() const { return m_m3surfaceVariant; }
    void setM3surfaceVariant(const QColor &v) { if (m_m3surfaceVariant != v) { m_m3surfaceVariant = v; emit m3colorsChanged(); } }

    QColor m3onSurfaceVariant() const { return m_m3onSurfaceVariant; }
    void setM3onSurfaceVariant(const QColor &v) { if (m_m3onSurfaceVariant != v) { m_m3onSurfaceVariant = v; emit m3colorsChanged(); } }

    QColor m3inverseSurface() const { return m_m3inverseSurface; }
    void setM3inverseSurface(const QColor &v) { if (m_m3inverseSurface != v) { m_m3inverseSurface = v; emit m3colorsChanged(); } }

    QColor m3inverseOnSurface() const { return m_m3inverseOnSurface; }
    void setM3inverseOnSurface(const QColor &v) { if (m_m3inverseOnSurface != v) { m_m3inverseOnSurface = v; emit m3colorsChanged(); } }

    QColor m3outline() const { return m_m3outline; }
    void setM3outline(const QColor &v) { if (m_m3outline != v) { m_m3outline = v; emit m3colorsChanged(); } }

    QColor m3outlineVariant() const { return m_m3outlineVariant; }
    void setM3outlineVariant(const QColor &v) { if (m_m3outlineVariant != v) { m_m3outlineVariant = v; emit m3colorsChanged(); } }

    QColor m3shadow() const { return m_m3shadow; }
    void setM3shadow(const QColor &v) { if (m_m3shadow != v) { m_m3shadow = v; emit m3colorsChanged(); } }

    QColor m3scrim() const { return m_m3scrim; }
    void setM3scrim(const QColor &v) { if (m_m3scrim != v) { m_m3scrim = v; emit m3colorsChanged(); } }

    QColor m3primary() const { return m_m3primary; }
    void setM3primary(const QColor &v) { if (m_m3primary != v) { m_m3primary = v; emit m3colorsChanged(); } }

    QColor m3onPrimary() const { return m_m3onPrimary; }
    void setM3onPrimary(const QColor &v) { if (m_m3onPrimary != v) { m_m3onPrimary = v; emit m3colorsChanged(); } }

    QColor m3primaryContainer() const { return m_m3primaryContainer; }
    void setM3primaryContainer(const QColor &v) { if (m_m3primaryContainer != v) { m_m3primaryContainer = v; emit m3colorsChanged(); } }

    QColor m3onPrimaryContainer() const { return m_m3onPrimaryContainer; }
    void setM3onPrimaryContainer(const QColor &v) { if (m_m3onPrimaryContainer != v) { m_m3onPrimaryContainer = v; emit m3colorsChanged(); } }

    QColor m3secondary() const { return m_m3secondary; }
    void setM3secondary(const QColor &v) { if (m_m3secondary != v) { m_m3secondary = v; emit m3colorsChanged(); } }

    QColor m3onSecondary() const { return m_m3onSecondary; }
    void setM3onSecondary(const QColor &v) { if (m_m3onSecondary != v) { m_m3onSecondary = v; emit m3colorsChanged(); } }

    QColor m3secondaryContainer() const { return m_m3secondaryContainer; }
    void setM3secondaryContainer(const QColor &v) { if (m_m3secondaryContainer != v) { m_m3secondaryContainer = v; emit m3colorsChanged(); } }

    QColor m3onSecondaryContainer() const { return m_m3onSecondaryContainer; }
    void setM3onSecondaryContainer(const QColor &v) { if (m_m3onSecondaryContainer != v) { m_m3onSecondaryContainer = v; emit m3colorsChanged(); } }

    QColor m3tertiary() const { return m_m3tertiary; }
    void setM3tertiary(const QColor &v) { if (m_m3tertiary != v) { m_m3tertiary = v; emit m3colorsChanged(); } }

    QColor m3onTertiary() const { return m_m3onTertiary; }
    void setM3onTertiary(const QColor &v) { if (m_m3onTertiary != v) { m_m3onTertiary = v; emit m3colorsChanged(); } }

    QColor m3tertiaryContainer() const { return m_m3tertiaryContainer; }
    void setM3tertiaryContainer(const QColor &v) { if (m_m3tertiaryContainer != v) { m_m3tertiaryContainer = v; emit m3colorsChanged(); } }

    QColor m3onTertiaryContainer() const { return m_m3onTertiaryContainer; }
    void setM3onTertiaryContainer(const QColor &v) { if (m_m3onTertiaryContainer != v) { m_m3onTertiaryContainer = v; emit m3colorsChanged(); } }

    QColor m3error() const { return m_m3error; }
    void setM3error(const QColor &v) { if (m_m3error != v) { m_m3error = v; emit m3colorsChanged(); } }

    QColor m3onError() const { return m_m3onError; }
    void setM3onError(const QColor &v) { if (m_m3onError != v) { m_m3onError = v; emit m3colorsChanged(); } }

    QColor m3errorContainer() const { return m_m3errorContainer; }
    void setM3errorContainer(const QColor &v) { if (m_m3errorContainer != v) { m_m3errorContainer = v; emit m3colorsChanged(); } }

    QColor m3onErrorContainer() const { return m_m3onErrorContainer; }
    void setM3onErrorContainer(const QColor &v) { if (m_m3onErrorContainer != v) { m_m3onErrorContainer = v; emit m3colorsChanged(); } }

signals:
    void m3colorsChanged();

private:
    bool m_darkmode = false;
    bool m_transparent = false;
    QColor m_m3background = QColor("#161217");
    QColor m_m3onBackground = QColor("#EAE0E7");
    QColor m_m3surface = QColor("#161217");
    QColor m_m3surfaceDim = QColor("#161217");
    QColor m_m3surfaceBright = QColor("#3D373D");
    QColor m_m3surfaceContainerLowest = QColor("#110D12");
    QColor m_m3surfaceContainerLow = QColor("#1F1A1F");
    QColor m_m3surfaceContainer = QColor("#231E23");
    QColor m_m3surfaceContainerHigh = QColor("#2D282E");
    QColor m_m3surfaceContainerHighest = QColor("#383339");
    QColor m_m3onSurface = QColor("#EAE0E7");
    QColor m_m3surfaceVariant = QColor("#4C444D");
    QColor m_m3onSurfaceVariant = QColor("#CFC3CD");
    QColor m_m3inverseSurface = QColor("#EAE0E7");
    QColor m_m3inverseOnSurface = QColor("#342F34");
    QColor m_m3outline = QColor("#988E97");
    QColor m_m3outlineVariant = QColor("#4C444D");
    QColor m_m3shadow = QColor("#000000");
    QColor m_m3scrim = QColor("#000000");
    QColor m_m3primary = QColor("#E5B6F2");
    QColor m_m3onPrimary = QColor("#452152");
    QColor m_m3primaryContainer = QColor("#5D386A");
    QColor m_m3onPrimaryContainer = QColor("#F9D8FF");
    QColor m_m3secondary = QColor("#D5C0D7");
    QColor m_m3onSecondary = QColor("#392C3D");
    QColor m_m3secondaryContainer = QColor("#534457");
    QColor m_m3onSecondaryContainer = QColor("#F2DCF3");
    QColor m_m3tertiary = QColor("#F5B7B3");
    QColor m_m3onTertiary = QColor("#4C2523");
    QColor m_m3tertiaryContainer = QColor("#BA837F");
    QColor m_m3onTertiaryContainer = QColor("#000000");
    QColor m_m3error = QColor("#FFB4AB");
    QColor m_m3onError = QColor("#690005");
    QColor m_m3errorContainer = QColor("#93000A");
    QColor m_m3onErrorContainer = QColor("#FFDAD6");
};

class RoundingGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(int unsharpen READ unsharpen CONSTANT)
    Q_PROPERTY(int unsharpenmore READ unsharpenmore CONSTANT)
    Q_PROPERTY(int verysmall READ verysmall CONSTANT)
    Q_PROPERTY(int small READ small CONSTANT)
    Q_PROPERTY(int normal READ normal CONSTANT)
    Q_PROPERTY(int large READ large CONSTANT)
    Q_PROPERTY(int verylarge READ verylarge CONSTANT)
    Q_PROPERTY(int full READ full CONSTANT)
    Q_PROPERTY(int screenRounding READ screenRounding CONSTANT)
    Q_PROPERTY(int windowRounding READ windowRounding CONSTANT)
public:
    explicit RoundingGroup(QObject *parent = nullptr) : QObject(parent) {}
    int unsharpen() const { return 2; }
    int unsharpenmore() const { return 6; }
    int verysmall() const { return 8; }
    int small() const { return 12; }
    int normal() const { return 17; }
    int large() const { return 23; }
    int verylarge() const { return 30; }
    int full() const { return 9999; }
    int screenRounding() const { return large(); }
    int windowRounding() const { return 18; }
};

class FontFamily : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString main READ main CONSTANT)
    Q_PROPERTY(QString title READ title CONSTANT)
    Q_PROPERTY(QString iconMaterial READ iconMaterial CONSTANT)
    Q_PROPERTY(QString iconNerd READ iconNerd CONSTANT)
    Q_PROPERTY(QString monospace READ monospace CONSTANT)
    Q_PROPERTY(QString reading READ reading CONSTANT)
    Q_PROPERTY(QString expressive READ expressive CONSTANT)
public:
    explicit FontFamily(QObject *parent = nullptr) : QObject(parent) {}
    QString main() const { return "Rubik"; }
    QString title() const { return "Gabarito"; }
    QString iconMaterial() const { return "Material Symbols Rounded"; }
    QString iconNerd() const { return "JetBrains Mono NF"; }
    QString monospace() const { return "JetBrains Mono NF"; }
    QString reading() const { return "Readex Pro"; }
    QString expressive() const { return "Space Grotesk"; }
};

class FontPixelSize : public QObject {
    Q_OBJECT
    Q_PROPERTY(int smallest READ smallest CONSTANT)
    Q_PROPERTY(int smaller READ smaller CONSTANT)
    Q_PROPERTY(int smallie READ smallie CONSTANT)
    Q_PROPERTY(int small READ small CONSTANT)
    Q_PROPERTY(int normal READ normal CONSTANT)
    Q_PROPERTY(int large READ large CONSTANT)
    Q_PROPERTY(int larger READ larger CONSTANT)
    Q_PROPERTY(int huge READ huge CONSTANT)
    Q_PROPERTY(int hugeass READ hugeass CONSTANT)
    Q_PROPERTY(int title READ title CONSTANT)
public:
    explicit FontPixelSize(QObject *parent = nullptr) : QObject(parent) {}
    int smallest() const { return 10; }
    int smaller() const { return 12; }
    int smallie() const { return 13; }
    int small() const { return 15; }
    int normal() const { return 16; }
    int large() const { return 17; }
    int larger() const { return 19; }
    int huge() const { return 22; }
    int hugeass() const { return 23; }
    int title() const { return huge(); }
};

class FontGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* family READ family CONSTANT)
    Q_PROPERTY(QObject* pixelSize READ pixelSize CONSTANT)
public:
    explicit FontGroup(QObject *parent = nullptr)
        : QObject(parent), m_family(new FontFamily(this)), m_pixelSize(new FontPixelSize(this)) {}
    QObject *family() const { return m_family; }
    QObject *pixelSize() const { return m_pixelSize; }
private:
    FontFamily *m_family;
    FontPixelSize *m_pixelSize;
};

class AnimationCurvesGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVector<qreal> expressiveFastSpatial READ expressiveFastSpatial CONSTANT)
    Q_PROPERTY(QVector<qreal> expressiveDefaultSpatial READ expressiveDefaultSpatial CONSTANT)
    Q_PROPERTY(QVector<qreal> expressiveSlowSpatial READ expressiveSlowSpatial CONSTANT)
    Q_PROPERTY(QVector<qreal> expressiveEffects READ expressiveEffects CONSTANT)
    Q_PROPERTY(QVector<qreal> emphasized READ emphasized CONSTANT)
    Q_PROPERTY(QVector<qreal> emphasizedFirstHalf READ emphasizedFirstHalf CONSTANT)
    Q_PROPERTY(QVector<qreal> emphasizedLastHalf READ emphasizedLastHalf CONSTANT)
    Q_PROPERTY(QVector<qreal> emphasizedAccel READ emphasizedAccel CONSTANT)
    Q_PROPERTY(QVector<qreal> emphasizedDecel READ emphasizedDecel CONSTANT)
    Q_PROPERTY(QVector<qreal> standard READ standard CONSTANT)
    Q_PROPERTY(QVector<qreal> standardAccel READ standardAccel CONSTANT)
    Q_PROPERTY(QVector<qreal> standardDecel READ standardDecel CONSTANT)
    Q_PROPERTY(qreal expressiveFastSpatialDuration READ expressiveFastSpatialDuration CONSTANT)
    Q_PROPERTY(qreal expressiveDefaultSpatialDuration READ expressiveDefaultSpatialDuration CONSTANT)
    Q_PROPERTY(qreal expressiveSlowSpatialDuration READ expressiveSlowSpatialDuration CONSTANT)
    Q_PROPERTY(qreal expressiveEffectsDuration READ expressiveEffectsDuration CONSTANT)
public:
    explicit AnimationCurvesGroup(QObject *parent = nullptr) : QObject(parent) {}
    QVector<qreal> expressiveFastSpatial() const { return {0.42, 1.67, 0.21, 0.90, 1, 1}; }
    QVector<qreal> expressiveDefaultSpatial() const { return {0.38, 1.21, 0.22, 1.00, 1, 1}; }
    QVector<qreal> expressiveSlowSpatial() const { return {0.39, 1.29, 0.35, 0.98, 1, 1}; }
    QVector<qreal> expressiveEffects() const { return {0.34, 0.80, 0.34, 1.00, 1, 1}; }
    QVector<qreal> emphasized() const { return {0.05, 0, 2.0/15, 0.06, 1.0/6, 0.4, 5.0/24, 0.82, 0.25, 1, 1, 1}; }
    QVector<qreal> emphasizedFirstHalf() const { return {0.05, 0, 2.0/15, 0.06, 1.0/6, 0.4, 5.0/24, 0.82}; }
    QVector<qreal> emphasizedLastHalf() const { return {5.0/24, 0.82, 0.25, 1, 1, 1}; }
    QVector<qreal> emphasizedAccel() const { return {0.3, 0, 0.8, 0.15, 1, 1}; }
    QVector<qreal> emphasizedDecel() const { return {0.05, 0.7, 0.1, 1, 1, 1}; }
    QVector<qreal> standard() const { return {0.2, 0, 0, 1, 1, 1}; }
    QVector<qreal> standardAccel() const { return {0.3, 0, 1, 1, 1, 1}; }
    QVector<qreal> standardDecel() const { return {0, 0, 0, 1, 1, 1}; }
    qreal expressiveFastSpatialDuration() const { return 350; }
    qreal expressiveDefaultSpatialDuration() const { return 500; }
    qreal expressiveSlowSpatialDuration() const { return 650; }
    qreal expressiveEffectsDuration() const { return 200; }
};

class AnimationSpec : public QObject {
    Q_OBJECT
    Q_PROPERTY(int duration READ duration CONSTANT)
    Q_PROPERTY(int type READ type CONSTANT)
    Q_PROPERTY(QVector<qreal> bezierCurve READ bezierCurve CONSTANT)
    Q_PROPERTY(int velocity READ velocity CONSTANT)
    Q_PROPERTY(QQmlComponent* numberAnimation READ numberAnimation CONSTANT)
    Q_PROPERTY(QQmlComponent* colorAnimation READ colorAnimation CONSTANT)

public:
    AnimationSpec(int duration, int type, QVector<qreal> bezierCurve, int velocity, QObject *parent = nullptr)
        : QObject(parent), m_duration(duration), m_type(type), m_bezierCurve(std::move(bezierCurve)), m_velocity(velocity) {}

    int duration() const { return m_duration; }
    int type() const { return m_type; }
    QVector<qreal> bezierCurve() const { return m_bezierCurve; }
    int velocity() const { return m_velocity; }

    QQmlComponent *numberAnimation();
    QQmlComponent *colorAnimation();

private:
    int m_duration;
    int m_type;
    QVector<qreal> m_bezierCurve;
    int m_velocity;
    QQmlComponent *m_numberAnimation = nullptr;
    QQmlComponent *m_colorAnimation = nullptr;
};

// Easing.BezierSpline in QML == QEasingCurve::BezierSpline == 26
static constexpr int EASING_BEZIER_SPLINE = 26;
// Easing.OutExpo == QEasingCurve::OutExpo == 8
static constexpr int EASING_OUT_EXPO = 8;

class AnimationGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* elementMove READ elementMove CONSTANT)
    Q_PROPERTY(QObject* elementMoveEnter READ elementMoveEnter CONSTANT)
    Q_PROPERTY(QObject* elementMoveExit READ elementMoveExit CONSTANT)
    Q_PROPERTY(QObject* elementMoveFast READ elementMoveFast CONSTANT)
    Q_PROPERTY(QObject* elementResize READ elementResize CONSTANT)
    Q_PROPERTY(QObject* clickBounce READ clickBounce CONSTANT)
    Q_PROPERTY(QObject* scroll READ scroll CONSTANT)
    Q_PROPERTY(QObject* menuDecel READ menuDecel CONSTANT)
public:
    explicit AnimationGroup(AnimationCurvesGroup *curves, QObject *parent = nullptr) : QObject(parent) {
        m_elementMove = new AnimationSpec(curves->expressiveDefaultSpatialDuration(), EASING_BEZIER_SPLINE, curves->expressiveDefaultSpatial(), 650, this);
        m_elementMoveEnter = new AnimationSpec(400, EASING_BEZIER_SPLINE, curves->emphasizedDecel(), 650, this);
        m_elementMoveExit = new AnimationSpec(200, EASING_BEZIER_SPLINE, curves->emphasizedAccel(), 650, this);
        m_elementMoveFast = new AnimationSpec(curves->expressiveEffectsDuration(), EASING_BEZIER_SPLINE, curves->expressiveEffects(), 850, this);
        m_elementResize = new AnimationSpec(300, EASING_BEZIER_SPLINE, curves->emphasized(), 650, this);
        m_clickBounce = new AnimationSpec(200, EASING_BEZIER_SPLINE, curves->expressiveFastSpatial(), 850, this);
        m_scroll = new AnimationSpec(200, EASING_BEZIER_SPLINE, curves->standardDecel(), 0, this);
        m_menuDecel = new AnimationSpec(350, EASING_OUT_EXPO, {}, 0, this);
    }
    QObject *elementMove() const { return m_elementMove; }
    QObject *elementMoveEnter() const { return m_elementMoveEnter; }
    QObject *elementMoveExit() const { return m_elementMoveExit; }
    QObject *elementMoveFast() const { return m_elementMoveFast; }
    QObject *elementResize() const { return m_elementResize; }
    QObject *clickBounce() const { return m_clickBounce; }
    QObject *scroll() const { return m_scroll; }
    QObject *menuDecel() const { return m_menuDecel; }
private:
    AnimationSpec *m_elementMove, *m_elementMoveEnter, *m_elementMoveExit, *m_elementMoveFast,
                  *m_elementResize, *m_clickBounce, *m_scroll, *m_menuDecel;
};

class SizesGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal baseBarHeight READ baseBarHeight NOTIFY sizesChanged)
    Q_PROPERTY(qreal barHeight READ barHeight WRITE setBarHeight NOTIFY sizesChanged)
    Q_PROPERTY(qreal barCenterSideModuleWidth READ barCenterSideModuleWidth WRITE setBarCenterSideModuleWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal barCenterSideModuleWidthShortened READ barCenterSideModuleWidthShortened NOTIFY sizesChanged)
    Q_PROPERTY(qreal barCenterSideModuleWidthHellaShortened READ barCenterSideModuleWidthHellaShortened NOTIFY sizesChanged)
    Q_PROPERTY(qreal barShortenScreenWidthThreshold READ barShortenScreenWidthThreshold NOTIFY sizesChanged)
    Q_PROPERTY(qreal barHellaShortenScreenWidthThreshold READ barHellaShortenScreenWidthThreshold NOTIFY sizesChanged)
    Q_PROPERTY(qreal elevationMargin READ elevationMargin NOTIFY sizesChanged)
    Q_PROPERTY(qreal fabShadowRadius READ fabShadowRadius NOTIFY sizesChanged)
    Q_PROPERTY(qreal fabHoveredShadowRadius READ fabHoveredShadowRadius NOTIFY sizesChanged)
    Q_PROPERTY(qreal hyprlandGapsOut READ hyprlandGapsOut NOTIFY sizesChanged)
    Q_PROPERTY(qreal mediaControlsWidth READ mediaControlsWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal mediaControlsHeight READ mediaControlsHeight NOTIFY sizesChanged)
    Q_PROPERTY(qreal notificationPopupWidth READ notificationPopupWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal osdWidth READ osdWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal searchWidthCollapsed READ searchWidthCollapsed NOTIFY sizesChanged)
    Q_PROPERTY(qreal searchWidth READ searchWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal sidebarWidth READ sidebarWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal sidebarWidthExtended READ sidebarWidthExtended NOTIFY sizesChanged)
    Q_PROPERTY(qreal baseVerticalBarWidth READ baseVerticalBarWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal verticalBarWidth READ verticalBarWidth WRITE setVerticalBarWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal wallpaperSelectorWidth READ wallpaperSelectorWidth NOTIFY sizesChanged)
    Q_PROPERTY(qreal wallpaperSelectorHeight READ wallpaperSelectorHeight NOTIFY sizesChanged)
    Q_PROPERTY(qreal wallpaperSelectorItemMargins READ wallpaperSelectorItemMargins NOTIFY sizesChanged)
    Q_PROPERTY(qreal wallpaperSelectorItemPadding READ wallpaperSelectorItemPadding NOTIFY sizesChanged)
    Q_PROPERTY(qreal dashboardWidth READ dashboardWidth NOTIFY sizesChanged)

public:
    explicit SizesGroup(QObject *parent = nullptr) : QObject(parent) {}
    qreal baseBarHeight() const { return 40; }
    qreal barHeight() const { return m_barHeight; }
    void setBarHeight(qreal v) { if (m_barHeight != v) { m_barHeight = v; emit sizesChanged(); } }
    qreal barCenterSideModuleWidth() const { return m_barCenterSideModuleWidth; }
    void setBarCenterSideModuleWidth(qreal v) { if (m_barCenterSideModuleWidth != v) { m_barCenterSideModuleWidth = v; emit sizesChanged(); } }
    qreal barCenterSideModuleWidthShortened() const { return 280; }
    qreal barCenterSideModuleWidthHellaShortened() const { return 190; }
    qreal barShortenScreenWidthThreshold() const { return 1200; }
    qreal barHellaShortenScreenWidthThreshold() const { return 1000; }
    qreal elevationMargin() const { return 10; }
    qreal fabShadowRadius() const { return 5; }
    qreal fabHoveredShadowRadius() const { return 7; }
    qreal hyprlandGapsOut() const { return 5; }
    qreal mediaControlsWidth() const { return 440; }
    qreal mediaControlsHeight() const { return 160; }
    qreal notificationPopupWidth() const { return 410; }
    qreal osdWidth() const { return 180; }
    qreal searchWidthCollapsed() const { return 260; }
    qreal searchWidth() const { return 450; }
    qreal sidebarWidth() const { return 460; }
    qreal sidebarWidthExtended() const { return 750; }
    qreal baseVerticalBarWidth() const { return 46; }
    qreal verticalBarWidth() const { return m_verticalBarWidth; }
    void setVerticalBarWidth(qreal v) { if (m_verticalBarWidth != v) { m_verticalBarWidth = v; emit sizesChanged(); } }
    qreal wallpaperSelectorWidth() const { return 1200; }
    qreal wallpaperSelectorHeight() const { return 690; }
    qreal wallpaperSelectorItemMargins() const { return 8; }
    qreal wallpaperSelectorItemPadding() const { return 6; }
    qreal dashboardWidth() const { return 600; }

signals:
    void sizesChanged();

private:
    qreal m_barHeight = 0;
    qreal m_barCenterSideModuleWidth = 0;
    qreal m_verticalBarWidth = 0;
};

class ColorsGroup : public QObject {
    Q_OBJECT
    Q_PROPERTY(QColor colSubtext READ colSubtext NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer0 READ colLayer0 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer0 READ colOnLayer0 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer0Hover READ colLayer0Hover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer0Active READ colLayer0Active NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer0Border READ colLayer0Border NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer1 READ colLayer1 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer1 READ colOnLayer1 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer1Inactive READ colOnLayer1Inactive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer2 READ colLayer2 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer2 READ colOnLayer2 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer2Disabled READ colOnLayer2Disabled NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer1Hover READ colLayer1Hover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer1Active READ colLayer1Active NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer2Hover READ colLayer2Hover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer2Active READ colLayer2Active NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer2Disabled READ colLayer2Disabled NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer3 READ colLayer3 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer3 READ colOnLayer3 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer3Hover READ colLayer3Hover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer3Active READ colLayer3Active NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer4 READ colLayer4 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnLayer4 READ colOnLayer4 NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer4Hover READ colLayer4Hover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colLayer4Active READ colLayer4Active NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimary READ colPrimary NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnPrimary READ colOnPrimary NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimaryHover READ colPrimaryHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimaryActive READ colPrimaryActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimaryContainer READ colPrimaryContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimaryContainerHover READ colPrimaryContainerHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colPrimaryContainerActive READ colPrimaryContainerActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnPrimaryContainer READ colOnPrimaryContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondary READ colSecondary NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondaryHover READ colSecondaryHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondaryActive READ colSecondaryActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondaryContainer READ colSecondaryContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondaryContainerHover READ colSecondaryContainerHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSecondaryContainerActive READ colSecondaryContainerActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiary READ colTertiary NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiaryHover READ colTertiaryHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiaryActive READ colTertiaryActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiaryContainer READ colTertiaryContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiaryContainerHover READ colTertiaryContainerHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTertiaryContainerActive READ colTertiaryContainerActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnSecondaryContainer READ colOnSecondaryContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainerLow READ colSurfaceContainerLow NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainer READ colSurfaceContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainerHigh READ colSurfaceContainerHigh NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainerHighest READ colSurfaceContainerHighest NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainerHighestHover READ colSurfaceContainerHighestHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colSurfaceContainerHighestActive READ colSurfaceContainerHighestActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnSurface READ colOnSurface NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnSurfaceVariant READ colOnSurfaceVariant NOTIFY colorsChanged)
    Q_PROPERTY(QColor colTooltip READ colTooltip NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnTooltip READ colOnTooltip NOTIFY colorsChanged)
    Q_PROPERTY(QColor colScrim READ colScrim NOTIFY colorsChanged)
    Q_PROPERTY(QColor colShadow READ colShadow NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOutline READ colOutline NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOutlineVariant READ colOutlineVariant NOTIFY colorsChanged)
    Q_PROPERTY(QColor colError READ colError NOTIFY colorsChanged)
    Q_PROPERTY(QColor colErrorHover READ colErrorHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colErrorActive READ colErrorActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnError READ colOnError NOTIFY colorsChanged)
    Q_PROPERTY(QColor colErrorContainer READ colErrorContainer NOTIFY colorsChanged)
    Q_PROPERTY(QColor colErrorContainerHover READ colErrorContainerHover NOTIFY colorsChanged)
    Q_PROPERTY(QColor colErrorContainerActive READ colErrorContainerActive NOTIFY colorsChanged)
    Q_PROPERTY(QColor colOnErrorContainer READ colOnErrorContainer NOTIFY colorsChanged)

public:
    explicit ColorsGroup(M3Colors *m3, QObject *parent = nullptr);
    void recompute(qreal backgroundTransparency, qreal contentTransparency, bool extraBackgroundTint);

    QColor colSubtext() const { return m_colSubtext; }
    QColor colLayer0() const { return m_colLayer0; }
    QColor colOnLayer0() const { return m_colOnLayer0; }
    QColor colLayer0Hover() const { return m_colLayer0Hover; }
    QColor colLayer0Active() const { return m_colLayer0Active; }
    QColor colLayer0Border() const { return m_colLayer0Border; }
    QColor colLayer1() const { return m_colLayer1; }
    QColor colOnLayer1() const { return m_colOnLayer1; }
    QColor colOnLayer1Inactive() const { return m_colOnLayer1Inactive; }
    QColor colLayer2() const { return m_colLayer2; }
    QColor colOnLayer2() const { return m_colOnLayer2; }
    QColor colOnLayer2Disabled() const { return m_colOnLayer2Disabled; }
    QColor colLayer1Hover() const { return m_colLayer1Hover; }
    QColor colLayer1Active() const { return m_colLayer1Active; }
    QColor colLayer2Hover() const { return m_colLayer2Hover; }
    QColor colLayer2Active() const { return m_colLayer2Active; }
    QColor colLayer2Disabled() const { return m_colLayer2Disabled; }
    QColor colLayer3() const { return m_colLayer3; }
    QColor colOnLayer3() const { return m_colOnLayer3; }
    QColor colLayer3Hover() const { return m_colLayer3Hover; }
    QColor colLayer3Active() const { return m_colLayer3Active; }
    QColor colLayer4() const { return m_colLayer4; }
    QColor colOnLayer4() const { return m_colOnLayer4; }
    QColor colLayer4Hover() const { return m_colLayer4Hover; }
    QColor colLayer4Active() const { return m_colLayer4Active; }
    QColor colPrimary() const { return m_colPrimary; }
    QColor colOnPrimary() const { return m_colOnPrimary; }
    QColor colPrimaryHover() const { return m_colPrimaryHover; }
    QColor colPrimaryActive() const { return m_colPrimaryActive; }
    QColor colPrimaryContainer() const { return m_colPrimaryContainer; }
    QColor colPrimaryContainerHover() const { return m_colPrimaryContainerHover; }
    QColor colPrimaryContainerActive() const { return m_colPrimaryContainerActive; }
    QColor colOnPrimaryContainer() const { return m_colOnPrimaryContainer; }
    QColor colSecondary() const { return m_colSecondary; }
    QColor colSecondaryHover() const { return m_colSecondaryHover; }
    QColor colSecondaryActive() const { return m_colSecondaryActive; }
    QColor colSecondaryContainer() const { return m_colSecondaryContainer; }
    QColor colSecondaryContainerHover() const { return m_colSecondaryContainerHover; }
    QColor colSecondaryContainerActive() const { return m_colSecondaryContainerActive; }
    QColor colTertiary() const { return m_colTertiary; }
    QColor colTertiaryHover() const { return m_colTertiaryHover; }
    QColor colTertiaryActive() const { return m_colTertiaryActive; }
    QColor colTertiaryContainer() const { return m_colTertiaryContainer; }
    QColor colTertiaryContainerHover() const { return m_colTertiaryContainerHover; }
    QColor colTertiaryContainerActive() const { return m_colTertiaryContainerActive; }
    QColor colOnSecondaryContainer() const { return m_colOnSecondaryContainer; }
    QColor colSurfaceContainerLow() const { return m_colSurfaceContainerLow; }
    QColor colSurfaceContainer() const { return m_colSurfaceContainer; }
    QColor colSurfaceContainerHigh() const { return m_colSurfaceContainerHigh; }
    QColor colSurfaceContainerHighest() const { return m_colSurfaceContainerHighest; }
    QColor colSurfaceContainerHighestHover() const { return m_colSurfaceContainerHighestHover; }
    QColor colSurfaceContainerHighestActive() const { return m_colSurfaceContainerHighestActive; }
    QColor colOnSurface() const { return m_colOnSurface; }
    QColor colOnSurfaceVariant() const { return m_colOnSurfaceVariant; }
    QColor colTooltip() const { return m_colTooltip; }
    QColor colOnTooltip() const { return m_colOnTooltip; }
    QColor colScrim() const { return m_colScrim; }
    QColor colShadow() const { return m_colShadow; }
    QColor colOutline() const { return m_colOutline; }
    QColor colOutlineVariant() const { return m_colOutlineVariant; }
    QColor colError() const { return m_colError; }
    QColor colErrorHover() const { return m_colErrorHover; }
    QColor colErrorActive() const { return m_colErrorActive; }
    QColor colOnError() const { return m_colOnError; }
    QColor colErrorContainer() const { return m_colErrorContainer; }
    QColor colErrorContainerHover() const { return m_colErrorContainerHover; }
    QColor colErrorContainerActive() const { return m_colErrorContainerActive; }
    QColor colOnErrorContainer() const { return m_colOnErrorContainer; }

signals:
    void colorsChanged();

private:
    M3Colors *m_m3;
    QColor m_colSubtext, m_colLayer0, m_colOnLayer0, m_colLayer0Hover, m_colLayer0Active, m_colLayer0Border,
           m_colLayer1, m_colOnLayer1, m_colOnLayer1Inactive, m_colLayer2, m_colOnLayer2, m_colOnLayer2Disabled,
           m_colLayer1Hover, m_colLayer1Active, m_colLayer2Hover, m_colLayer2Active, m_colLayer2Disabled,
           m_colLayer3, m_colOnLayer3, m_colLayer3Hover, m_colLayer3Active, m_colLayer4, m_colOnLayer4,
           m_colLayer4Hover, m_colLayer4Active, m_colPrimary, m_colOnPrimary, m_colPrimaryHover, m_colPrimaryActive,
           m_colPrimaryContainer, m_colPrimaryContainerHover, m_colPrimaryContainerActive, m_colOnPrimaryContainer,
           m_colSecondary, m_colSecondaryHover, m_colSecondaryActive, m_colSecondaryContainer,
           m_colSecondaryContainerHover, m_colSecondaryContainerActive, m_colTertiary, m_colTertiaryHover,
           m_colTertiaryActive, m_colTertiaryContainer, m_colTertiaryContainerHover, m_colTertiaryContainerActive,
           m_colOnSecondaryContainer, m_colSurfaceContainerLow, m_colSurfaceContainer, m_colSurfaceContainerHigh,
           m_colSurfaceContainerHighest, m_colSurfaceContainerHighestHover, m_colSurfaceContainerHighestActive,
           m_colOnSurface, m_colOnSurfaceVariant, m_colTooltip, m_colOnTooltip, m_colScrim, m_colShadow,
           m_colOutline, m_colOutlineVariant, m_colError, m_colErrorHover, m_colErrorActive, m_colOnError,
           m_colErrorContainer, m_colErrorContainerHover, m_colErrorContainerActive, m_colOnErrorContainer;
};

class Appearance : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QObject* m3colors READ m3colors CONSTANT)
    Q_PROPERTY(QObject* colors READ colors CONSTANT)
    Q_PROPERTY(QObject* rounding READ rounding CONSTANT)
    Q_PROPERTY(QObject* font READ font CONSTANT)
    Q_PROPERTY(QObject* animationCurves READ animationCurves CONSTANT)
    Q_PROPERTY(QObject* animation READ animation CONSTANT)
    Q_PROPERTY(QObject* sizes READ sizes CONSTANT)
    Q_PROPERTY(QString syntaxHighlightingTheme READ syntaxHighlightingTheme CONSTANT)

    Q_PROPERTY(QString wallpaperPath READ wallpaperPath WRITE setWallpaperPath NOTIFY wallpaperPathChanged)
    Q_PROPERTY(QString thumbnailPath READ thumbnailPath WRITE setThumbnailPath NOTIFY thumbnailPathChanged)
    Q_PROPERTY(qreal backgroundTransparency READ backgroundTransparency WRITE setBackgroundTransparency NOTIFY backgroundTransparencyChanged)
    Q_PROPERTY(qreal contentTransparency READ contentTransparency WRITE setContentTransparency NOTIFY contentTransparencyChanged)
    Q_PROPERTY(bool extraBackgroundTint READ extraBackgroundTint WRITE setExtraBackgroundTint NOTIFY extraBackgroundTintChanged)

public:
    explicit Appearance(QObject *parent = nullptr);

    QObject *m3colors() const { return m_m3colors; }
    QObject *colors() const { return m_colors; }
    QObject *rounding() const { return m_rounding; }
    QObject *font() const { return m_font; }
    QObject *animationCurves() const { return m_animationCurves; }
    QObject *animation() const { return m_animation; }
    QObject *sizes() const { return m_sizes; }
    QString syntaxHighlightingTheme() const { return "ayu Light"; }

    QString wallpaperPath() const { return m_wallpaperPath; }
    void setWallpaperPath(const QString &v) { if (m_wallpaperPath != v) { m_wallpaperPath = v; emit wallpaperPathChanged(); } }
    QString thumbnailPath() const { return m_thumbnailPath; }
    void setThumbnailPath(const QString &v) { if (m_thumbnailPath != v) { m_thumbnailPath = v; emit thumbnailPathChanged(); } }

    qreal backgroundTransparency() const { return m_backgroundTransparency; }
    void setBackgroundTransparency(qreal v);
    qreal contentTransparency() const { return m_contentTransparency; }
    void setContentTransparency(qreal v);
    bool extraBackgroundTint() const { return m_extraBackgroundTint; }
    void setExtraBackgroundTint(bool v);

signals:
    void wallpaperPathChanged();
    void thumbnailPathChanged();
    void backgroundTransparencyChanged();
    void contentTransparencyChanged();
    void extraBackgroundTintChanged();

private:
    M3Colors *m_m3colors;
    ColorsGroup *m_colors;
    RoundingGroup *m_rounding;
    FontGroup *m_font;
    AnimationCurvesGroup *m_animationCurves;
    AnimationGroup *m_animation;
    SizesGroup *m_sizes;

    QString m_wallpaperPath;
    QString m_thumbnailPath;
    qreal m_backgroundTransparency = 0;
    qreal m_contentTransparency = 0;
    bool m_extraBackgroundTint = false;
};