#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QVector>
#include <QJSValue>

class Fuzzy : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit Fuzzy(QObject *parent = nullptr);

    Q_INVOKABLE double computeScore(const QString &search, const QString &target) const;
    Q_INVOKABLE double computeTextMatchScore(const QString &search, const QString &target) const;

    Q_INVOKABLE QJSValue prepare(const QJSValue &target) const;
    Q_INVOKABLE QJSValue go(const QString &search, const QJSValue &targets, const QJSValue &options = QJSValue()) const;

private:
    struct PreparedInfo {
        QString lower;
        QVector<int> lowerCodes;
        int bitflags = 0;
        QVector<int> nextBeginningIndexes;
    };

    PreparedInfo prepareInfo(const QString &str, bool isTarget) const;
    QVector<int> prepareNextBeginningIndexes(const QString &target) const;
    QString removeAccents(const QString &str) const;
    
    double normalizeScore(double score) const;
};