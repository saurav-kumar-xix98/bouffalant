#include <gtest/gtest.h>

#include "leetcode/LC067924Game.hpp"

TEST(leetcode, LC067924Game_Testcase1) {
    ASSERT_EQ(true, LC067924Game::judgePoint24({4, 1, 8, 7}));
}

TEST(leetcode, LC067924Game_Testcase2) {
    ASSERT_EQ(false, LC067924Game::judgePoint24({1, 2, 1, 2}));
}
