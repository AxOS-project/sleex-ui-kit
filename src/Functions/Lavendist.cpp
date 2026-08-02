// Original code from https://github.com/koeqaife/hyprland-material-you
// Original code license: GPLv3
// Translated to C++ (Qt/QObject) from JS (originally Cython) with an LLM and reviewed

#include "Lavendist.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

namespace {

inline int min3(int a, int b, int c) {
    return a < b && a < c ? a : (b < c ? b : c);
}

inline int max2i(int a, int b) {
    return a > b ? a : b;
}

inline int min2i(int a, int b) {
    return a < b ? a : b;
}

} // namespace

Levendist::Levendist(QObject* parent) : QObject(parent) {}

int Levendist::levenshteinDistance(QString s1, QString s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    if (len2 > len1) {
        std::swap(s1, s2);
        std::swap(len1, len2);
    }

    std::vector<int> prev(len2 + 1);
    std::vector<int> curr(len2 + 1);

    for (int j = 0; j <= len2; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        curr[0] = i;
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            curr[j] = min3(prev[j] + 1, curr[j - 1] + 1, prev[j - 1] + cost);
        }
        std::swap(prev, curr);
    }

    return prev[len2];
}

double Levendist::partialRatio(const QString& shortS, const QString& longS) {
    int lenS = shortS.length();
    int lenL = longS.length();
    double best = 0.0;

    if (lenS == 0) return 1.0;

    for (int i = 0; i <= lenL - lenS; i++) {
        QString sub = longS.mid(i, lenS);
        int dist = levenshteinDistance(shortS, sub);
        double score = 1.0 - (static_cast<double>(dist) / lenS);
        if (score > best) best = score;
    }

    return best;
}

double Levendist::computeScore(const QString& s1, const QString& s2) const {
    if (s1 == s2) return 1.0;

    int dist = levenshteinDistance(s1, s2);
    int maxLen = max2i(s1.length(), s2.length());
    if (maxLen == 0) return 1.0;

    double full = 1.0 - (static_cast<double>(dist) / maxLen);
    double part = s1.length() < s2.length() ? partialRatio(s1, s2) : partialRatio(s2, s1);

    double score = 0.85 * full + 0.15 * part;

    if (!s1.isEmpty() && !s2.isEmpty() && s1[0] != s2[0]) {
        score -= 0.05;
    }

    int lenDiff = std::abs(s1.length() - s2.length());
    if (lenDiff >= 3) {
        score -= 0.05 * lenDiff / maxLen;
    }

    int commonPrefixLen = 0;
    int minLen = min2i(s1.length(), s2.length());
    for (int i = 0; i < minLen; i++) {
        if (s1[i] == s2[i]) {
            commonPrefixLen++;
        } else {
            break;
        }
    }
    score += 0.02 * commonPrefixLen;

    if (s1.contains(s2) || s2.contains(s1)) {
        score += 0.06;
    }

    return std::max(0.0, std::min(1.0, score));
}

double Levendist::computeTextMatchScore(const QString& s1, const QString& s2) const {
    if (s1 == s2) return 1.0;

    int dist = levenshteinDistance(s1, s2);
    int maxLen = max2i(s1.length(), s2.length());
    if (maxLen == 0) return 1.0;

    double full = 1.0 - (static_cast<double>(dist) / maxLen);
    double part = s1.length() < s2.length() ? partialRatio(s1, s2) : partialRatio(s2, s1);

    double score = 0.4 * full + 0.6 * part;

    int lenDiff = std::abs(s1.length() - s2.length());
    if (lenDiff >= 10) {
        score -= 0.02 * lenDiff / maxLen;
    }

    int commonPrefixLen = 0;
    int minLen = min2i(s1.length(), s2.length());
    for (int i = 0; i < minLen; i++) {
        if (s1[i] == s2[i]) {
            commonPrefixLen++;
        } else {
            break;
        }
    }
    score += 0.01 * commonPrefixLen;

    if (s1.contains(s2) || s2.contains(s1)) {
        score += 0.2;
    }

    return std::max(0.0, std::min(1.0, score));
}