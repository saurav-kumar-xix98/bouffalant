#include "leetcode/LC1032StreamOfCharacters.hpp"

#include <array>

namespace LC1032StreamOfCharacters {
    struct TrieNode {
        bool isWord;
        std::array<TrieNode*, 26> children{};
        TrieNode();
        void addWord(const std::string &word, int pos);
    };
}

LC1032StreamOfCharacters::StreamChecker::StreamChecker(const std::vector<std::string>& words) {
    trie = new TrieNode();
    for (auto &word: words) {
        trie->addWord(word, 0);
    }
    iterators = { trie };
}

bool LC1032StreamOfCharacters::StreamChecker::query(const char letter) {
    std::vector nextIterators = { trie };
    bool found = false;
    int i = letter - 'a';
    for (const auto node : iterators) {
        if (node->children[i] == nullptr)
            continue;
        nextIterators.push_back(node->children[i]);
        if (node->children[i]->isWord)
            found = true;
    }
    iterators.swap(nextIterators);
    return found;
}

LC1032StreamOfCharacters::TrieNode::TrieNode() {
    isWord = false;
    children.fill(nullptr);
}

void LC1032StreamOfCharacters::TrieNode::addWord(const std::string& word, const int pos) {
    if (word.length() == pos) {
        isWord = true;
        return;
    }

    const int i = word[pos] - 'a';
    if (children[i] == nullptr) {
        children[i] = new TrieNode();
    }

    children[i]->addWord(word, pos + 1);
}
