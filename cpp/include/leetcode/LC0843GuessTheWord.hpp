#pragma once

#include <string>
#include <unordered_set>
#include <cstdint>
#include <vector>

namespace LC0843GuessTheWord {
    class Master {
        std::string secret;
        std::unordered_set<std::string> words;
        uint8_t allowed_guesses;
        bool guessed;
    public:
        Master(std::string secret, const std::vector<std::string> &words, uint8_t allowed_guesses);
        bool isGuessed() const;
        int guess(const std::string &word);
    };

    void findSecretWord(const std::vector<std::string>& words, Master& master);
}
