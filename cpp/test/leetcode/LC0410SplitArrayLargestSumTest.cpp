#include <gtest/gtest.h>

#include "leetcode/LC0410SplitArrayLargestSum.hpp"

TEST(leetcode, LC0410SplitArrayLargestSum_Testcase1) {
    ASSERT_EQ(18, LC0410SplitArrayLargestSum::splitArray({7,2,5,10,8}, 2));
}

TEST(leetcode, LC0410SplitArrayLargestSum_Testcase2) {
    ASSERT_EQ(9, LC0410SplitArrayLargestSum::splitArray({1,2,3,4,5}, 2));
}
