#include <QObject>
#include <QQmlEngine>
#include <QColor>

class ColorUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit ColorUtils(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE static QColor colorWithHueOf(const QColor &color1, const QColor &color2);
    Q_INVOKABLE static QColor colorWithSaturationOf(const QColor &color1, const QColor &color2);
    Q_INVOKABLE static QColor colorWithLightness(const QColor &color, qreal lightness);
    Q_INVOKABLE static QColor colorWithLightnessOf(const QColor &color1, const QColor &color2);
    Q_INVOKABLE static QColor adaptToAccent(const QColor &color1, const QColor &color2);
    Q_INVOKABLE static QColor mix(const QColor &color1, const QColor &color2, qreal percentage = 0.5);
    Q_INVOKABLE static QColor transparentize(const QColor &color, qreal percentage = 1.0);
    Q_INVOKABLE static QColor applyAlpha(const QColor &color, qreal alpha);
    Q_INVOKABLE static QString stringToColor(const QString &str);
    Q_INVOKABLE static QString getContrastingTextColor(const QColor &bgColor);
};