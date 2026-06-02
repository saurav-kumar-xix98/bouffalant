#include <gtest/gtest.h>

#include "leetcode/LC0843GuessTheWord.hpp"

TEST(leetcode, LC0843GuessTheWord_Testcase1) {
    const std::string secret = "acckzz";
    const std::vector<std::string> words = {"acckzz","ccbazz","eiowzz","abcczz"};
    constexpr uint8_t allowed_guesses = 10;
    LC0843GuessTheWord::Master master(secret, words, allowed_guesses);
    LC0843GuessTheWord::findSecretWord(words, master);
    ASSERT_TRUE(master.isGuessed());
}

TEST(leetcode, LC0843GuessTheWord_Testcase2) {
    const std::string secret = "hamada";
    const std::vector<std::string> words = {"hamada","khaled"};
    constexpr uint8_t allowed_guesses = 10;
    LC0843GuessTheWord::Master master(secret, words, allowed_guesses);
    LC0843GuessTheWord::findSecretWord(words, master);
    ASSERT_TRUE(master.isGuessed());
}
