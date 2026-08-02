// Translated from a Quickshell QML Singleton to C++ (Qt/QObject) with an LLM and reviewed

#include "StringUtils.hpp"

#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QVariantMap>
#include <cmath>

StringUtils::StringUtils(QObject* parent) : QObject(parent) {}

QString StringUtils::format(const QString& str, const QVariantList& args) const {
    static const QRegularExpression re(QStringLiteral("\\{(\\d+)\\}"));

    QString result;
    result.reserve(str.size());
    int lastIndex = 0;

    auto it = re.globalMatch(str);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        result += str.mid(lastIndex, match.capturedStart() - lastIndex);

        bool ok = false;
        int index = match.captured(1).toInt(&ok);
        if (ok && index >= 0 && index < args.size() && args[index].isValid()) {
            result += args[index].toString();
        } else {
            result += match.captured(0);
        }

        lastIndex = match.capturedEnd();
    }
    result += str.mid(lastIndex);

    return result;
}

QString StringUtils::getDomain(const QString& url) const {
    static const QRegularExpression re(QStringLiteral("^(?:https?://)?(?:www\\.)?([^/]+)"));
    QRegularExpressionMatch match = re.match(url);
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return QString();
}

QString StringUtils::getBaseUrl(const QString& url) const {
    static const QRegularExpression re(QStringLiteral("^(https?://[^/]+)(/.*)?$"));
    QRegularExpressionMatch match = re.match(url);
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return QString();
}

QString StringUtils::shellSingleQuoteEscape(const QString& str) const {
    QString result = str;
    return result.replace(QLatin1Char('\''), QStringLiteral("'\\''"));
}

QVariantList StringUtils::splitMarkdownBlocks(const QString& markdown) const {
    static const QRegularExpression re(
        QStringLiteral("```(\\w+)?\\n([\\s\\S]*?)```|<think>([\\s\\S]*?)</think>"));

    QVariantList result;
    int lastIndex = 0;

    auto it = re.globalMatch(markdown);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();

        if (match.capturedStart() > lastIndex) {
            QString text = markdown.mid(lastIndex, match.capturedStart() - lastIndex);
            if (!text.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("text");
                entry[QStringLiteral("content")] = text;
                result.append(entry);
            }
        }

        QString whole = match.captured(0);
        if (whole.startsWith(QStringLiteral("```"))) {
            QString code = match.captured(2);
            if (!code.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("code");
                entry[QStringLiteral("lang")] = match.captured(1);
                entry[QStringLiteral("content")] = code;
                entry[QStringLiteral("completed")] = true;
                result.append(entry);
            }
        } else if (whole.startsWith(QStringLiteral("<think>"))) {
            QString think = match.captured(3);
            if (!think.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("think");
                entry[QStringLiteral("content")] = think;
                entry[QStringLiteral("completed")] = true;
                result.append(entry);
            }
        }

        lastIndex = match.capturedEnd();
    }

    // Handle any remaining text after the last match
    if (lastIndex < markdown.length()) {
        QString text = markdown.mid(lastIndex);
        int thinkStart = text.indexOf(QStringLiteral("<think>"));
        int codeStart = text.indexOf(QStringLiteral("```"));

        if (thinkStart != -1 && (codeStart == -1 || thinkStart < codeStart)) {
            QString beforeThink = text.left(thinkStart);
            if (!beforeThink.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("text");
                entry[QStringLiteral("content")] = beforeThink;
                result.append(entry);
            }
            QString thinkContent = text.mid(thinkStart + 7);
            if (!thinkContent.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("think");
                entry[QStringLiteral("content")] = thinkContent;
                entry[QStringLiteral("completed")] = false;
                result.append(entry);
            }
        } else if (codeStart != -1) {
            QString beforeCode = text.left(codeStart);
            if (!beforeCode.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("text");
                entry[QStringLiteral("content")] = beforeCode;
                result.append(entry);
            }

            static const QRegularExpression langRe(QStringLiteral("^(\\w+)?\\n"));
            QString afterFence = text.mid(codeStart + 3);
            QRegularExpressionMatch langMatch = langRe.match(afterFence);

            QString lang;
            int codeContentStart = codeStart + 3;
            if (langMatch.hasMatch()) {
                lang = langMatch.captured(1);
                codeContentStart += langMatch.captured(0).length();
            } else if (codeStart + 3 < text.length() && text.at(codeStart + 3) == QLatin1Char('\n')) {
                codeContentStart += 1;
            }

            QString codeContent = text.mid(codeContentStart);
            if (!codeContent.trimmed().isEmpty()) {
                QVariantMap entry;
                entry[QStringLiteral("type")] = QStringLiteral("code");
                entry[QStringLiteral("lang")] = lang;
                entry[QStringLiteral("content")] = codeContent;
                entry[QStringLiteral("completed")] = false;
                result.append(entry);
            }
        } else if (!text.trimmed().isEmpty()) {
            QVariantMap entry;
            entry[QStringLiteral("type")] = QStringLiteral("text");
            entry[QStringLiteral("content")] = text;
            result.append(entry);
        }
    }

    return result;
}

QString StringUtils::escapeBackslashes(const QString& str) const {
    QString result = str;
    return result.replace(QLatin1Char('\\'), QStringLiteral("\\\\"));
}

QString StringUtils::wordWrap(const QString& str, int maxLen) const {
    if (str.isEmpty()) return QString();

    QStringList words = str.split(QLatin1Char(' '));
    QStringList lines;
    QString current;

    for (const QString& word : words) {
        QString candidate = current + (current.length() > 0 ? QStringLiteral(" ") : QString()) + word;
        if (candidate.length() > maxLen) {
            if (current.length() > 0) {
                lines.append(current);
            }
            current = word;
        } else {
            current = candidate;
        }
    }
    if (current.length() > 0) {
        lines.append(current);
    }

    return lines.join(QStringLiteral("\n"));
}

QString StringUtils::cleanMusicTitle(const QString& title) const {
    if (title.isEmpty()) return QString();

    QString result = title;

    static const QRegularExpression roundBrackets(QStringLiteral("^ *\\([^)]*\\) *"));
    static const QRegularExpression squareBrackets(QStringLiteral("^ *\\[[^\\]]*\\] *"));
    static const QRegularExpression curlyBrackets(QStringLiteral("^ *\\{[^}]*\\} *"));
    static const QRegularExpression touhouBrackets(QStringLiteral("^ *【[^】]*】"));
    static const QRegularExpression angleBrackets(QStringLiteral("^ *《[^》]*》"));
    static const QRegularExpression cornerBrackets(QStringLiteral("^ *「[^」]*」"));
    static const QRegularExpression whiteCornerBrackets(QStringLiteral("^ *『[^』]*』"));

    result.replace(roundBrackets, QStringLiteral(" "));
    result.replace(squareBrackets, QStringLiteral(" "));
    result.replace(curlyBrackets, QStringLiteral(" "));
    result.replace(touhouBrackets, QString());
    result.replace(angleBrackets, QString());
    result.replace(cornerBrackets, QString());
    result.replace(whiteCornerBrackets, QString());

    return result.trimmed();
}

QString StringUtils::friendlyTimeForSeconds(double seconds) const {
    if (std::isnan(seconds) || seconds < 0) return QStringLiteral("0:00");

    qint64 total = static_cast<qint64>(std::floor(seconds));
    qint64 h = total / 3600;
    qint64 m = (total % 3600) / 60;
    qint64 s = total % 60;

    if (h > 0) {
        return QStringLiteral("%1:%2:%3")
            .arg(h)
            .arg(m, 2, 10, QLatin1Char('0'))
            .arg(s, 2, 10, QLatin1Char('0'));
    }
    return QStringLiteral("%1:%2").arg(m).arg(s, 2, 10, QLatin1Char('0'));
}

QString StringUtils::escapeHtml(const QString& str) const {
    QString result = str;
    result.replace(QLatin1Char('&'), QStringLiteral("&amp;"));
    result.replace(QLatin1Char('<'), QStringLiteral("&lt;"));
    result.replace(QLatin1Char('>'), QStringLiteral("&gt;"));
    result.replace(QLatin1Char('"'), QStringLiteral("&quot;"));
    result.replace(QLatin1Char('\''), QStringLiteral("&#39;"));
    return result;
}

QString StringUtils::cleanCliphistEntry(const QString& str) const {
    static const QRegularExpression re(QStringLiteral("^\\d+\\t"));
    QString result = str;
    return result.replace(re, QString());
}

bool StringUtils::stringListContainsSubstring(const QString& str, const QStringList& substrings) const {
    for (const QString& sub : substrings) {
        if (str.contains(sub)) {
            return true;
        }
    }
    return false;
}

QString StringUtils::cleanPrefix(const QString& str, const QString& prefix) const {
    if (str.startsWith(prefix)) {
        return str.mid(prefix.length());
    }
    return str;
}

QString StringUtils::cleanOnePrefix(const QString& str, const QStringList& prefixes) const {
    for (const QString& prefix : prefixes) {
        if (str.startsWith(prefix)) {
            return str.mid(prefix.length());
        }
    }
    return str;
}