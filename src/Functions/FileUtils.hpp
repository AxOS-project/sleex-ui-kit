#include <QObject>
#include <QQmlEngine>

class FileUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit FileUtils(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString trimFileProtocol(const QString &str) const;
    Q_INVOKABLE QString fileNameForPath(const QString &str) const;
    Q_INVOKABLE QString trimFileExt(const QString &str) const;
};

