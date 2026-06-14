#pragma once

#include <vector>
#include <string>

namespace LC1032StreamOfCharacters {
    struct TrieNode;

    class StreamChecker {
        TrieNode* trie;
        std::vector<TrieNode*> iterators;
    public:
        explicit StreamChecker(const std::vector<std::string>& words);
        bool query(char letter);
    };
}
