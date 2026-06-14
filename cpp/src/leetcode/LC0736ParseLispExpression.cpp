#include "leetcode/LC0736ParseLispExpression.hpp"

#include <unordered_map>
#include <vector>

namespace {
    std::vector<std::string> tokenize(const std::string &exp);
    int evaluateRecursive(const std::vector<std::string> &tokens, int &pos, std::vector<std::unordered_map<std::string, int>> &scopes);
}

int LC0736ParseLispExpression::evaluate(const std::string& expression) {
    const std::vector<std::string> tokens = tokenize(expression);
    std::vector<std::unordered_map<std::string, int>> scopes;
    int start = 0;
    return evaluateRecursive(tokens, start, scopes);
}

namespace {
    std::vector<std::string> tokenize(const std::string &exp) {
        std::vector<std::string> result;
        std::string token;
        for (char c : exp) {
            if (c == ' ' || c == '(' || c == ')') {
                if (!token.empty()) {
                    result.push_back(token);
                    token = "";
                }
                if (c != ' ')
                    result.emplace_back(1, c);
            } else {
                token.push_back(c);
            }
        }
        if (!token.empty())
            result.push_back(token);
        return result;
    }

    bool isInteger(const std::string &token) {
        return token[0] == '-' || (token[0] >= '0' && token[0] <= '9');
    }

    bool isVariable(const std::string &token) {
        return token[0] >= 'a' && token[0] <= 'z' && token != "let" && token != "add" && token != "mult";
    }

    int evaluateRecursive(const std::vector<std::string> &tokens, int &pos, std::vector<std::unordered_map<std::string, int>> &scopes) {
        std::string token = tokens[pos++];
        if (isInteger(token)) {
            return stoi(token);
        }
        if (isVariable(token)) {
            for (size_t i = scopes.size(); i > 0;) {
                i--;
                if (auto itr = scopes[i].find(token); itr != scopes[i].end()) {
                    return itr->second;
                }
            }
            return -1;
        }
        if (token != "(") {
            return -1;
        }
        token = tokens[pos++];
        if (token == "add" || token == "mult") {
            const int v1 = evaluateRecursive(tokens, pos, scopes);
            const int v2 = evaluateRecursive(tokens, pos, scopes);
            if (tokens[pos++] != ")") {
                return -1;
            }
            return token == "add" ? v1 + v2 : v1 * v2;
        }
        if (token != "let") {
            return -1;
        }
        scopes.emplace_back();
        while (true) {
            if (isVariable(tokens[pos]) && tokens[pos + 1] != ")") {
                const std::string& variable = tokens[pos++];
                const int value = evaluateRecursive(tokens, pos, scopes);
                scopes.back()[variable] = value;
                continue;
            }
            const int value = evaluateRecursive(tokens, pos, scopes);
            if (tokens[pos++] != ")") {
                return -1;
            }
            scopes.pop_back();
            return value;
        }
    }
}
