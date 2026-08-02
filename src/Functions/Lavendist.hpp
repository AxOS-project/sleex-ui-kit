// Original code from https://github.com/koeqaife/hyprland-material-you
// Original code license: GPLv3
// Translated to C++ (Qt/QObject) from JS (originally Cython) with an LLM and reviewed

#pragma once

#include <QObject>
#include <QString>
#include <qqmlintegration.h>

class Levendist : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit Levendist(QObject* parent = nullptr);

    Q_INVOKABLE double computeScore(const QString& s1, const QString& s2) const;
    Q_INVOKABLE double computeTextMatchScore(const QString& s1, const QString& s2) const;

private:
    static int levenshteinDistance(QString s1, QString s2);
    static double partialRatio(const QString& shortS, const QString& longS);
};