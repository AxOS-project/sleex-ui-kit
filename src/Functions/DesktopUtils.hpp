#include <QObject>
#include <QQmlEngine>

class DesktopUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit DesktopUtils(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString getIconName(const QString &fileName, bool isDir) const;
    Q_INVOKABLE QString getFileType(const QString &fileName, bool isDir) const;
    Q_INVOKABLE QString getAppId(const QString &fileName) const;
};