#include "MaterialThemeLoader.hpp"
#include "Appearance.hpp"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QDebug>

MaterialThemeLoader::MaterialThemeLoader(M3Colors *m3colors, QObject *parent)
    : QObject(parent)
    , m_m3colors(m3colors)
{
    m_delayTimer.setSingleShot(true);
    m_delayTimer.setInterval(100);

    connect(&m_delayTimer, &QTimer::timeout, this, &MaterialThemeLoader::readAndApply);
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &MaterialThemeLoader::onFileChanged);
    connect(&m_watcher, &QFileSystemWatcher::directoryChanged, this, &MaterialThemeLoader::onDirectoryChanged);
}

void MaterialThemeLoader::setFilePath(const QString &path)
{
    const QString localPath = path.startsWith(u"file://") ? QUrl(path).toLocalFile() : path;

    if (m_filePath == localPath)
        return;

    m_filePath = localPath;
    updateWatchers();
    readAndApply();

    emit filePathChanged();
}

void MaterialThemeLoader::setRaceConditionDelay(int ms)
{
    if (m_delayTimer.interval() == ms)
        return;
    m_delayTimer.setInterval(ms);
    emit raceConditionDelayChanged();
}

void MaterialThemeLoader::reapplyTheme()
{
    readAndApply();
}

void MaterialThemeLoader::updateWatchers()
{
    if (!m_watcher.files().isEmpty())
        m_watcher.removePaths(m_watcher.files());
    if (!m_watcher.directories().isEmpty())
        m_watcher.removePaths(m_watcher.directories());

    if (m_filePath.isEmpty())
        return;

    const QFileInfo info(m_filePath);
    if (info.exists() && info.isFile()) {
        m_watcher.addPath(m_filePath);
    } else {
        // File doesn't exist yet — watch parent directory to catch its creation
        const QString dirPath = info.absolutePath();
        if (QDir(dirPath).exists()) {
            m_watcher.addPath(dirPath);
        }
    }
}

void MaterialThemeLoader::onFileChanged(const QString &path)
{
    Q_UNUSED(path)
    updateWatchers();
    m_delayTimer.start();
}

void MaterialThemeLoader::onDirectoryChanged(const QString &dirPath)
{
    Q_UNUSED(dirPath)
    if (QFile::exists(m_filePath)) {
        updateWatchers();
        m_delayTimer.start();
    }
}

void MaterialThemeLoader::readAndApply()
{
    if (!m_m3colors)
        return;

    if (m_filePath.isEmpty()) {
        m_m3colors->resetToDefaults();
        return;
    }

    QFile file(m_filePath);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "[MaterialThemeLoader] Theme file missing or unreadable:" << m_filePath
                   << "- reverting to M3Colors defaults.";
        updateWatchers();
        m_m3colors->resetToDefaults();
        return;
    }

    const QByteArray content = file.readAll();
    if (content.trimmed().isEmpty() || !parseAndApply(content)) {
        qWarning() << "[MaterialThemeLoader] Invalid or empty JSON in:" << m_filePath
                   << "- reverting to M3Colors defaults.";
        m_m3colors->resetToDefaults();
    }
}

bool MaterialThemeLoader::parseAndApply(const QByteArray &fileContent)
{
    QJsonParseError err;
    const QJsonDocument doc = QJsonDocument::fromJson(fileContent, &err);
    if (err.error != QJsonParseError::NoError || !doc.isObject())
        return false;

    const QJsonObject json = doc.object();
    if (json.isEmpty())
        return false;

    QVariantMap mappedColors;
    for (auto it = json.begin(); it != json.end(); ++it) {
        mappedColors.insert(toM3CamelCase(it.key()), it.value().toVariant());
    }

    // Reset first so partial JSONs still fall back cleanly on missing keys
    m_m3colors->resetToDefaults();
    m_m3colors->applyAll(mappedColors);
    return true;
}

QString MaterialThemeLoader::toM3CamelCase(const QString &snakeCase)
{
    QString result;
    result.reserve(snakeCase.size() + 2);
    result.append(u"m3");

    bool capitalizeNext = false;
    for (QChar c : snakeCase) {
        if (c == u'_') {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            result.append(c.toUpper());
            capitalizeNext = false;
        } else {
            result.append(c);
        }
    }
    return result;
}