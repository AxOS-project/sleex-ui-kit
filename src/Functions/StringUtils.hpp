// Translated from a Quickshell QML Singleton to C++ (Qt/QObject) with an LLM and reviewed

#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <qqmlintegration.h>

class StringUtils : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit StringUtils(QObject* parent = nullptr);

    Q_INVOKABLE QString format(const QString& str, const QVariantList& args) const;
    Q_INVOKABLE QString getDomain(const QString& url) const;
    Q_INVOKABLE QString getBaseUrl(const QString& url) const;
    Q_INVOKABLE QString shellSingleQuoteEscape(const QString& str) const;
    Q_INVOKABLE QVariantList splitMarkdownBlocks(const QString& markdown) const;
    Q_INVOKABLE QString escapeBackslashes(const QString& str) const;
    Q_INVOKABLE QString wordWrap(const QString& str, int maxLen) const;
    Q_INVOKABLE QString cleanMusicTitle(const QString& title) const;
    Q_INVOKABLE QString friendlyTimeForSeconds(double seconds) const;
    Q_INVOKABLE QString escapeHtml(const QString& str) const;
    Q_INVOKABLE QString cleanCliphistEntry(const QString& str) const;
    Q_INVOKABLE bool stringListContainsSubstring(const QString& str, const QStringList& substrings) const;
    Q_INVOKABLE QString cleanPrefix(const QString& str, const QString& prefix) const;
    Q_INVOKABLE QString cleanOnePrefix(const QString& str, const QStringList& prefixes) const;
};