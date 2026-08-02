
#include "FileUtils.hpp"
#include <QFileInfo>
#include <QHash>
#include <QStringList>


/**
 * Trims the File protocol off the input string
 * @param {string} str
 * @returns {string}
 */
QString FileUtils::trimFileProtocol(const QString &str) const {
    return str.startsWith("file://") ? str.mid(7) : str;
}

/**
 * Extracts the file name from a file path
 * @param {string} str
 * @returns {string}
 */
QString FileUtils::fileNameForPath(const QString &str) const {
    return QFileInfo(trimFileProtocol(str)).fileName();
}


/**
 * Removes the file extension from a file path or name
 * @param {string} str
 * @returns {string}
 */
QString FileUtils::trimFileExt(const QString &str) const {
    QString trimmed = trimFileProtocol(str);
    int lastDot = trimmed.lastIndexOf(".");
    int lastSlash = trimmed.lastIndexOf("/");
    if (lastDot > -1 && lastDot > lastSlash) {
        return trimmed.left(lastDot);
    }
    return trimmed;
}

