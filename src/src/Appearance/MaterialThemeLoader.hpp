#pragma once

#include <QObject>
#include <QString>
#include <QTimer>
#include <QFileSystemWatcher>

class M3Colors;

class MaterialThemeLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    Q_PROPERTY(int raceConditionDelay READ raceConditionDelay WRITE setRaceConditionDelay NOTIFY raceConditionDelayChanged)

public:
    explicit MaterialThemeLoader(M3Colors *m3colors, QObject *parent = nullptr);

    QString filePath() const { return m_filePath; }
    void setFilePath(const QString &path);

    int raceConditionDelay() const { return m_delayTimer.interval(); }
    void setRaceConditionDelay(int ms);

    Q_INVOKABLE void reapplyTheme();

signals:
    void filePathChanged();
    void raceConditionDelayChanged();

private slots:
    void onFileChanged(const QString &path);
    void onDirectoryChanged(const QString &dirPath);
    void readAndApply();

private:
    void updateWatchers();
    bool parseAndApply(const QByteArray &fileContent);
    static QString toM3CamelCase(const QString &snakeCase);

    M3Colors *m_m3colors;
    QString m_filePath;
    QFileSystemWatcher m_watcher;
    QTimer m_delayTimer;
};