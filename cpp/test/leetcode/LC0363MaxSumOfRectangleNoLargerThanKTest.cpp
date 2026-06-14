#include <gtest/gtest.h>

#include "leetcode/LC0363MaxSumOfRectangleNoLargerThanK.hpp"

TEST(leetcode, LC0363MaxSumOfRectangleNoLargerThanK_Testcase1) {
    std::vector<std::vector<int>> matrix = {{1,0,1},{0,-2,3}};
    EXPECT_EQ(2, LC0363MaxSumOfRectangleNoLargerThanK::maxSumSubmatrix(matrix, 2));
}

TEST(leetcode, LC0363MaxSumOfRectangleNoLargerThanK_Testcase2) {
    std::vector<std::vector<int>> matrix = {{2,2,-1}};
    EXPECT_EQ(3, LC0363MaxSumOfRectangleNoLargerThanK::maxSumSubmatrix(matrix, 3));
}
