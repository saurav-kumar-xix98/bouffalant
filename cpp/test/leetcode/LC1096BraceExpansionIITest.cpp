#include <gtest/gtest.h>

#include "leetcode/LC1096BraceExpansionII.hpp"

TEST(leetcode, LC1096BraceExpansionII_Testcase1) {
    const std::string expression = "{a,b}{c,{d,e}}";
    const std::vector<std::string> expected = {"ac","ad","ae","bc","bd","be"};
    EXPECT_EQ(expected, LC1096BraceExpansionII::braceExpansionII(expression));
}

TEST(leetcode, LC1096BraceExpansionII_Testcase2) {
    const std::string expression = "{{a,z},a{b,c},{ab,z}}";
    const std::vector<std::string> expected = {"a","ab","ac","z"};
    EXPECT_EQ(expected, LC1096BraceExpansionII::braceExpansionII(expression));
}
