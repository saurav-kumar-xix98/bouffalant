#include <gtest/gtest.h>

#include "leetcode/LC1032StreamOfCharacters.hpp"

TEST(leetcode, LC1032StreamOfCharacters_Testcase1) {
    const std::vector<std::string> words = {"cd", "f", "kl"};
    LC1032StreamOfCharacters::StreamChecker streamChecker(words);

    ASSERT_EQ(false, streamChecker.query('a'));
    ASSERT_EQ(false, streamChecker.query('b'));
    ASSERT_EQ(false, streamChecker.query('c'));
    ASSERT_EQ(true, streamChecker.query('d'));
    ASSERT_EQ(false, streamChecker.query('e'));
    ASSERT_EQ(true, streamChecker.query('f'));
    ASSERT_EQ(false, streamChecker.query('g'));
    ASSERT_EQ(false, streamChecker.query('h'));
    ASSERT_EQ(false, streamChecker.query('i'));
    ASSERT_EQ(false, streamChecker.query('j'));
    ASSERT_EQ(false, streamChecker.query('k'));
    ASSERT_EQ(true, streamChecker.query('l'));
}
