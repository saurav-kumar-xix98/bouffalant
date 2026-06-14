#include <gtest/gtest.h>

#include "leetcode/LC1406StoneGameIII.hpp"

TEST(leetcode, LC1406StoneGameIII_Testcase1) {
    EXPECT_EQ("Bob", LC1406StoneGameIII::stoneGameIII({1,2,3,7}));
}

TEST(leetcode, LC1406StoneGameIII_Testcase2) {
    EXPECT_EQ("Alice", LC1406StoneGameIII::stoneGameIII({1,2,3,-9}));
}

TEST(leetcode, LC1406StoneGameIII_Testcase3) {
    EXPECT_EQ("Tie", LC1406StoneGameIII::stoneGameIII({1,2,3,6}));
}
