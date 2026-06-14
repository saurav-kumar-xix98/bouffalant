#include <gtest/gtest.h>

#include "leetcode/LC0042TrappingRainWater.hpp"

TEST(leetcode, LC0042TrappingRainWater_Testcase1) {
    ASSERT_EQ(6, LC0042TrappingRainWater::trap({0,1,0,2,1,0,1,3,2,1,2,1}));
}

TEST(leetcode, LC0042TrappingRainWater_Testcase2) {
    ASSERT_EQ(9, LC0042TrappingRainWater::trap({4,2,0,3,2,5}));
}
