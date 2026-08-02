#include "Fuzzy.hpp"
#include <cmath>
#include <QQmlEngine>
#include <algorithm>

Fuzzy::Fuzzy(QObject *parent) : QObject(parent) {}

QJSValue Fuzzy::prepare(const QJSValue &target) const {
    return target;
}

QJSValue Fuzzy::go(const QString &search, const QJSValue &targets, const QJSValue &options) const {
    QQmlEngine *engine = qmlEngine(this);
    if (!engine) return QJSValue();

    bool returnAll = false;
    QString key;
    if (options.isObject()) {
        if (options.hasProperty("all")) {
            returnAll = options.property("all").toBool();
        }
        if (options.hasProperty("key")) {
            key = options.property("key").toString();
        }
    }

    QString trimmedSearch = search.trimmed();
    QJSValue resultArr = engine->newArray();

    if (!targets.isArray()) {
        return resultArr;
    }

    quint32 length = targets.property("length").toUInt();
    if (trimmedSearch.isEmpty()) {
        if (!returnAll) {
            return resultArr;
        }
        quint32 outIdx = 0;
        for (quint32 i = 0; i < length; ++i) {
            QJSValue elem = targets.property(i);
            QJSValue itemObj = engine->newObject();
            itemObj.setProperty("obj", elem);
            itemObj.setProperty("score", 0);
            resultArr.setProperty(outIdx++, itemObj);
        }
        return resultArr;
    }

    struct ScoredItem {
        QJSValue elem;
        double score;
    };
    QVector<ScoredItem> scored;

    for (quint32 i = 0; i < length; ++i) {
        QJSValue elem = targets.property(i);
        QString targetStr;
        if (!key.isEmpty() && elem.isObject() && elem.hasProperty(key)) {
            targetStr = elem.property(key).toString();
        } else if (elem.isString()) {
            targetStr = elem.toString();
        } else {
            targetStr = elem.toString();
        }

        double score = computeScore(trimmedSearch, targetStr);
        if (score > 0.0) {
            scored.append({ elem, score });
        }
    }

    std::stable_sort(scored.begin(), scored.end(), [](const ScoredItem &a, const ScoredItem &b) {
        return a.score > b.score;
    });

    quint32 outIdx = 0;
    for (const auto &item : scored) {
        QJSValue itemObj = engine->newObject();
        itemObj.setProperty("obj", item.elem);
        itemObj.setProperty("score", item.score);
        resultArr.setProperty(outIdx++, itemObj);
    }

    return resultArr;
}

QString Fuzzy::removeAccents(const QString &str) const {
    QString normalized = str.normalized(QString::NormalizationForm_KD);
    QString result;
    for (const QChar &ch : normalized) {
        if (!ch.isMark()) {
            result.append(ch);
        }
    }
    return result;
}

Fuzzy::PreparedInfo Fuzzy::prepareInfo(const QString &str, bool isTarget) const {
    PreparedInfo info;
    QString cleaned = removeAccents(str);
    info.lower = cleaned.toLower();
    
    int strLen = info.lower.length();
    info.lowerCodes.reserve(strLen);
    
    for (int i = 0; i < strLen; ++i) {
        int lowerCode = info.lower.at(i).unicode();
        info.lowerCodes.append(lowerCode);
        
        if (lowerCode == 32) { // Esc
            continue;
        }
        
        int bit;
        if (lowerCode >= 97 && lowerCode <= 122) {
            bit = lowerCode - 97;
        } else if (lowerCode >= 48 && lowerCode <= 57) {
            bit = 26;
        } else if (lowerCode <= 127) {
            bit = 30;
        } else {
            bit = 31;
        }
        info.bitflags |= (1 << bit);
    }
    
    if (isTarget) {
        info.nextBeginningIndexes = prepareNextBeginningIndexes(cleaned);
    }
    
    return info;
}

QVector<int> Fuzzy::prepareNextBeginningIndexes(const QString &target) const {
    int targetLen = target.length();
    QVector<int> beginningIndexes;
    bool wasUpper = false;
    bool wasAlphanum = false;
    
    for (int i = 0; i < targetLen; ++i) {
        int targetCode = target.at(i).unicode();
        bool isUpper = (targetCode >= 65 && targetCode <= 90);
        bool isAlphanum = isUpper || (targetCode >= 97 && targetCode <= 122) || (targetCode >= 48 && targetCode <= 57);
        bool isBeginning = (isUpper && !wasUpper) || !wasAlphanum || !isAlphanum;
        
        wasUpper = isUpper;
        wasAlphanum = isAlphanum;
        
        if (isBeginning) {
            beginningIndexes.append(i);
        }
    }
    
    QVector<int> nextBeginningIndexes(targetLen, targetLen);
    if (beginningIndexes.isEmpty()) return nextBeginningIndexes;
    
    int lastIsBeginning = beginningIndexes[0];
    int lastIsBeginningI = 0;
    
    for (int i = 0; i < targetLen; ++i) {
        if (lastIsBeginning > i) {
            nextBeginningIndexes[i] = lastIsBeginning;
        } else {
            ++lastIsBeginningI;
            lastIsBeginning = (lastIsBeginningI < beginningIndexes.size()) ? beginningIndexes[lastIsBeginningI] : targetLen;
            nextBeginningIndexes[i] = lastIsBeginning;
        }
    }
    return nextBeginningIndexes;
}

double Fuzzy::normalizeScore(double score) const {
    if (score <= -INFINITY) return 0.0;
    if (score > 1.0) return score;
    return std::pow(M_E, (std::pow(-score + 1.0, 0.04307) - 1.0) * -2.0);
}

double Fuzzy::computeScore(const QString &search, const QString &target) const {
    if (search.trimmed().isEmpty() || target.isEmpty()) return 0.0;

    PreparedInfo searchInfo = prepareInfo(search, false);
    PreparedInfo targetInfo = prepareInfo(target, true);

    if ((searchInfo.bitflags & targetInfo.bitflags) != searchInfo.bitflags) {
        return 0.0;
    }

    int searchLen = searchInfo.lowerCodes.size();
    int targetLen = targetInfo.lowerCodes.size();
    int searchI = 0;
    int targetI = 0;

    QVector<int> matchesSimple;
    matchesSimple.reserve(searchLen);

    while (true) {
        if (searchInfo.lowerCodes[searchI] == targetInfo.lowerCodes[targetI]) {
            matchesSimple.append(targetI);
            ++searchI;
            if (searchI == searchLen) break;
        }
        ++targetI;
        if (targetI >= targetLen) return 0.0;
    }

    searchI = 0;
    bool successStrict = false;
    QVector<int> matchesStrict;
    matchesStrict.reserve(searchLen);

    targetI = (matchesSimple[0] == 0) ? 0 : targetInfo.nextBeginningIndexes[matchesSimple[0] - 1];
    int backtrackCount = 0;

    if (targetI != targetLen) {
        while (true) {
            if (targetI >= targetLen) {
                if (searchI <= 0) break;
                ++backtrackCount;
                if (backtrackCount > 200) break;
                
                --searchI;
                int lastMatch = matchesStrict.last();
                matchesStrict.removeLast();
                targetI = targetInfo.nextBeginningIndexes[lastMatch];
            } else {
                if (searchInfo.lowerCodes[searchI] == targetInfo.lowerCodes[targetI]) {
                    matchesStrict.append(targetI);
                    ++searchI;
                    if (searchI == searchLen) {
                        successStrict = true;
                        break;
                    }
                    ++targetI;
                } else {
                    targetI = targetInfo.nextBeginningIndexes[targetI];
                }
            }
        }
    }

    int substringIndex = (searchLen <= 1) ? -1 : targetInfo.lower.indexOf(searchInfo.lower, matchesSimple[0]);
    bool isSubstring = (substringIndex != -1);
    bool isSubstringBeginning = isSubstring && (substringIndex == 0 || targetInfo.nextBeginningIndexes[substringIndex - 1] == substringIndex);

    if (isSubstring && !isSubstringBeginning) {
        for (int i = targetInfo.nextBeginningIndexes[0]; i < targetLen; i = targetInfo.nextBeginningIndexes[i]) {
            if (i <= substringIndex) continue;
            int s = 0;
            for (; s < searchLen; ++s) {
                if (searchInfo.lowerCodes[s] != targetInfo.lowerCodes[i + s]) break;
            }
            if (s == searchLen) {
                substringIndex = i;
                isSubstringBeginning = true;
                break;
            }
        }
    }

    auto calculateScore = [&](const QVector<int>& matches) -> double {
        double score = 0;
        int extraMatchGroupCount = 0;
        
        for (int i = 1; i < searchLen; ++i) {
            if (matches[i] - matches[i - 1] != 1) {
                score -= matches[i];
                ++extraMatchGroupCount;
            }
        }
        
        int unmatchedDistance = matches.last() - matches.first() - (searchLen - 1);
        score -= (12 + unmatchedDistance) * extraMatchGroupCount;
        
        if (matches.first() != 0) {
            score -= matches.first() * matches.first() * 0.2;
        }

        if (!successStrict) {
            score *= 1000;
        } else {
            int uniqueBeginningIndexes = 1;
            for (int i = targetInfo.nextBeginningIndexes[0]; i < targetLen; i = targetInfo.nextBeginningIndexes[i]) {
                ++uniqueBeginningIndexes;
            }
            if (uniqueBeginningIndexes > 24) {
                score *= (uniqueBeginningIndexes - 24) * 10;
            }
        }

        score -= (targetLen - searchLen) / 2.0;

        if (isSubstring) score /= (1.0 + searchLen * searchLen);
        if (isSubstringBeginning) score /= (1.0 + searchLen * searchLen);

        score -= (targetLen - searchLen) / 2.0;
        return score;
    };

    double score = 0;
    if (!successStrict) {
        if (isSubstring) {
            for (int i = 0; i < searchLen; ++i) matchesSimple[i] = substringIndex + i;
        }
        score = calculateScore(matchesSimple);
    } else {
        if (isSubstringBeginning) {
            for (int i = 0; i < searchLen; ++i) matchesSimple[i] = substringIndex + i;
            score = calculateScore(matchesSimple);
        } else {
            score = calculateScore(matchesStrict);
        }
    }

    return normalizeScore(score);
}

double Fuzzy::computeTextMatchScore(const QString &search, const QString &target) const {
    return computeScore(search, target);
}