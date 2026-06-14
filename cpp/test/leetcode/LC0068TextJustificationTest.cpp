#include <gtest/gtest.h>

#include "leetcode/LC0068TextJustification.hpp"

TEST(leetcode, LC0068TextJustification_Testcase1) {
    const std::vector<std::string> words = {"This", "is", "an", "example", "of", "text",
        "justification."};
    constexpr int maxWidth = 16;
    const std::vector<std::string> output = LC0068TextJustification::fullJustify(words, maxWidth);
    const std::vector<std::string> expectedResult = {
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    ASSERT_EQ(output, expectedResult);
}

TEST(leetcode, LC0068TextJustification_Testcase2) {
    const std::vector<std::string> words = {"What","must","be","acknowledgment","shall","be"};
    constexpr int maxWidth = 16;
    const std::vector<std::string> output = LC0068TextJustification::fullJustify(words, maxWidth);
    const std::vector<std::string> expectedResult = {
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };
    ASSERT_EQ(output, expectedResult);
}

TEST(leetcode, LC0068TextJustification_Testcase3) {
    const std::vector<std::string> words = {"Science","is","what","we","understand","well",
        "enough","to","explain","to","a","computer.","Art","is","everything","else",
        "we","do"};
    constexpr int maxWidth = 20;
    const std::vector<std::string> output = LC0068TextJustification::fullJustify(words, maxWidth);
    const std::vector<std::string> expectedResult = {
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };
    ASSERT_EQ(output, expectedResult);
}
