#include "ColorUtils.hpp"
#include <QtMath>
#include <QColor>

/**
 * Returns a color with the hue of color2 and the saturation, value, and alpha of color1.
 *
 * @param {string} color1 - The base color (any Qt.color-compatible string).
 * @param {string} color2 - The color to take hue from.
 * @returns {Qt.rgba} The resulting color.
*/
QColor ColorUtils::colorWithHueOf(const QColor &color1, const QColor &color2) {
    return QColor::fromHsvF(color2.hsvHueF(), color1.hsvSaturationF(), color1.valueF(), color1.alphaF());
}

/**
 * Returns a color with the saturation of color2 and the hue/value/alpha of color1.
 *
 * @param {string} color1 - The base color (any Qt.color-compatible string).
 * @param {string} color2 - The color to take saturation from.
 * @returns {Qt.rgba} The resulting color.
 */
QColor ColorUtils::colorWithSaturationOf(const QColor &color1, const QColor &color2) {
    return QColor::fromHsvF(color1.hsvHueF(), color2.hsvSaturationF(), color1.valueF(), color1.alphaF());
}


/**
 * Returns a color with the given lightness and the hue, saturation, and alpha of the input color (using HSL).
 *
 * @param {string} color - The base color (any Qt.color-compatible string).
 * @param {number} lightness - The lightness value to use (0-1).
 * @returns {Qt.rgba} The resulting color.
 */
QColor ColorUtils::colorWithLightness(const QColor &color, qreal lightness) {
    return QColor::fromHslF(color.hslHueF(), color.hslSaturationF(), lightness, color.alphaF());
}


/**
 * Returns a color with the given lightness and the hue, saturation, and alpha of the input color (using HSL).
 *
 * @param {string} color - The base color (any Qt.color-compatible string).
 * @param {number} lightness - The lightness value to use (0-1).
 * @returns {Qt.rgba} The resulting color.
 */
QColor ColorUtils::colorWithLightnessOf(const QColor &color1, const QColor &color2) {
    return QColor::fromHslF(color1.hslHueF(), color1.hslSaturationF(), color2.lightnessF(), color1.alphaF());
}

/**
 * Adapts color1 to the accent (hue and saturation) of color2 using HSL, keeping lightness and alpha from color1.
 *
 * @param {string} color1 - The base color (any Qt.color-compatible string).
 * @param {string} color2 - The accent color.
 * @returns {Qt.rgba} The resulting color.
 */
QColor ColorUtils::adaptToAccent(const QColor &color1, const QColor &color2) {
    return QColor::fromHslF(color2.hslHueF(), color2.hslSaturationF(), color1.lightnessF(), color1.alphaF());
}


/**
 * Mixes two colors by a given percentage.
 *
 * @param {string} color1 - The first color (any Qt.color-compatible string).
 * @param {string} color2 - The second color.
 * @param {number} percentage - The mix ratio (0-1). 1 = all color1, 0 = all color2.
 * @returns {Qt.rgba} The resulting mixed color.
 */
QColor ColorUtils::mix(const QColor &color1, const QColor &color2, qreal percentage) {
    return QColor::fromRgbF(
        percentage * color1.redF() + (1 - percentage) * color2.redF(),
        percentage * color1.greenF() + (1 - percentage) * color2.greenF(),
        percentage * color1.blueF() + (1 - percentage) * color2.blueF(),
        percentage * color1.alphaF() + (1 - percentage) * color2.alphaF()
    );
}


/**
 * Transparentizes a color by a given percentage.
 *
 * @param {string} color - The color (any Qt.color-compatible string).
 * @param {number} percentage - The amount to transparentize (0-1).
 * @returns {Qt.rgba} The resulting color.
 */
QColor ColorUtils::transparentize(const QColor &color, qreal percentage) {
    QColor c = color;
    c.setAlphaF(c.alphaF() * (1.0 - percentage));
    return c;
}


/**
 * Sets the alpha channel of a color.
 *
 * @param {string} color - The base color (any Qt.color-compatible string).
 * @param {number} alpha - The desired alpha (0-1).
 * @returns {Qt.rgba} The resulting color with applied alpha.
 */
QColor ColorUtils::applyAlpha(const QColor &color, qreal alpha) {
    QColor c = color;
    c.setAlphaF(std::clamp(alpha, 0.0, 1.0));
    return c;
}

/**
 * Generates a hex color code from a string in a deterministic way.
 *
 * @param {string} str - The input string used to generate the color.
 * @returns {string} The resulting hex color in the format "#rrggbb".
 */
QString ColorUtils::stringToColor(const QString &str) {
    uint32_t hash = 0;
    if (str.isEmpty()) return "#000000";

    for (int i = 0; i < str.length(); i++) {
        hash = str[i].unicode() + ((hash << 5) - hash);
    }
    
    QString color = "#";
    for (int i = 0; i < 3; i++) {
        int value = (hash >> (i * 8)) & 255;
        color += QString("%1").arg(value, 2, 16, QChar('0'));
    }
    return color;
}

/**
 * Determines a contrasting text color (black or white) based on the background color's luminance.
 *
 * @param {string} bgColor - The background color (any Qt.color-compatible string).
 * @returns {string} The hex color ("#FFFFFF" or "#000000") that ensures high contrast.
 */
QString ColorUtils::getContrastingTextColor(const QColor &bgColor) {
    double r = bgColor.redF() <= 0.03928 ? bgColor.redF() / 12.92 : std::pow((bgColor.redF() + 0.055) / 1.055, 2.4);
    double g = bgColor.greenF() <= 0.03928 ? bgColor.greenF() / 12.92 : std::pow((bgColor.greenF() + 0.055) / 1.055, 2.4);
    double b = bgColor.blueF() <= 0.03928 ? bgColor.blueF() / 12.92 : std::pow((bgColor.blueF() + 0.055) / 1.055, 2.4);
    double luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;
    return luminance < 0.5 ? "#FFFFFF" : "#000000";
}