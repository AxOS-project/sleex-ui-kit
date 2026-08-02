
#include <QObject>
#include <QJSValue>
#include <QQmlEngine>

class ObjectUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit ObjectUtils(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QJSValue toPlainObject(QJSValue qtObj) const;
    Q_INVOKABLE void applyToQtObject(QJSValue qtObj, QJSValue jsonObj) const;
};
