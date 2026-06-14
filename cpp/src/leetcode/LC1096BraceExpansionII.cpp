#include "leetcode/LC1096BraceExpansionII.hpp"

#include <algorithm>
#include <set>

namespace {
    std::set<std::string> evaluate(const std::string &expression, int &pos);
}

std::vector<std::string> LC1096BraceExpansionII::braceExpansionII(const std::string& expression) {
    int pos = 0;

    std::set<std::string> result = evaluate("{" + expression + "}", pos);

    std::vector sortedResult(result.begin(), result.end());
    std::ranges::sort(sortedResult);
    return sortedResult;
}

namespace {
    bool isLowercaseLetter(const char c) {
        return c >= 'a' && c <= 'z';
    }

    std::set<std::string> concatenate(const std::set<std::string> &set1, const std::set<std::string> &set2) {
        std::set<std::string> result;
        for (const auto &s1 : set1) {
            for (const auto &s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    std::set<std::string> evaluate(const std::string &expression, int &pos) {
        if (isLowercaseLetter(expression[pos])) {
            std::string token;
            while (pos < expression.size() && isLowercaseLetter(expression[pos])) {
                token += expression[pos++];
            }
            return {token};
        }

        ++pos;

        std::set<std::string> unionSet;

        while (true) {
            std::set<std::string> term = evaluate(expression, pos);

            while (expression[pos] != '}' && expression[pos] != ',') {
                term = concatenate(term, evaluate(expression, pos));
            }

            unionSet.insert(term.begin(), term.end());

            if (expression[pos++] == '}') {
                break;
            }
        }

        return unionSet;
    }
}
