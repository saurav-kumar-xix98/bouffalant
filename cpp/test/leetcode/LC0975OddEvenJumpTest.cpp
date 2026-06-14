#include <gtest/gtest.h>

#include "leetcode/LC0975OddEvenJump.hpp"

TEST(leetcode, LC0975OddEvenJump_Testcase1) {
    const std::vector input = {10,13,12,14,15};
    ASSERT_EQ(2, LC0975OddEvenJump::oddEvenJumps(input));
}

TEST(leetcode, LC0975OddEvenJump_Testcase2) {
    const std::vector input = {2,3,1,1,4};
    ASSERT_EQ(3, LC0975OddEvenJump::oddEvenJumps(input));
}

TEST(leetcode, LC0975OddEvenJump_Testcase3) {
    const std::vector input = {5,1,3,4,2};
    ASSERT_EQ(3, LC0975OddEvenJump::oddEvenJumps(input));
}
