#include "leetcode/LC0068TextJustification.hpp"

#include <numeric>

namespace {
    std::string leftAlign(const std::vector<std::string> &words, int maxWidth);
    std::string justify(const std::vector<std::string> &words, int maxWidth);
}

std::vector<std::string> LC0068TextJustification::fullJustify(const std::vector<std::string> &words, const int maxWidth) {
    std::vector<std::string> result;
    std::vector<std::string> wordsInLine;

    size_t wordsInLineLength = 0;

    for (auto &word : words) {
        if (wordsInLineLength + wordsInLine.size() + word.size() > maxWidth) {
            result.push_back(justify(wordsInLine, maxWidth));

            wordsInLine = {};
            wordsInLineLength = 0;
        }

        wordsInLine.push_back(word);
        wordsInLineLength += word.size();
    }

    if (!wordsInLine.empty()) {
        result.push_back(leftAlign(wordsInLine, maxWidth));
    }

    return result;
}

namespace {
    std::string leftAlign(const std::vector<std::string> &words, const int maxWidth) {
        std::string line = words[0];

        for (int i = 1; i < words.size(); ++i) {
            line += " " + words[i];
        }
        line += std::string(maxWidth - line.size(), ' ');

        return line;
    }

    std::string justify(const std::vector<std::string> &words, const int maxWidth) {
        const size_t wordCount = words.size();
        if (wordCount == 1) {
            return leftAlign(words, maxWidth);
        }

        const size_t charCount = std::accumulate(words.begin(), words.end(), 0,
            [](const size_t count, const std::string &word) { return count + word.size(); });
        const size_t totalSpaceCount = maxWidth - charCount;
        const size_t gapCount = wordCount - 1;
        const size_t baseSpaceCount = totalSpaceCount / gapCount;
        const size_t extraSpaceCount = totalSpaceCount % gapCount;

        std::string line = words[0];

        for (int i = 1; i < wordCount; ++i) {
            const size_t spaceCount = baseSpaceCount + (i <= extraSpaceCount ? 1 : 0);
            line += std::string(spaceCount, ' ');
            line += words[i];
        }

        return line;
    }
}
