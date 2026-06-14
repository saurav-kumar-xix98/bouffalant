#include <gtest/gtest.h>

#include "leetcode/LC0329LongestIncreasingPathInAMatrix.hpp"

TEST(leetcode, LC0329LongestIncreasingPathInAMatrix_Testcase1) {
    std::vector<std::vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    ASSERT_EQ(4, LC0329LongestIncreasingPathInAMatrix::longestIncreasingPath(matrix));
}

TEST(leetcode, LC0329LongestIncreasingPathInAMatrix_Testcase2) {
    std::vector<std::vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    ASSERT_EQ(4, LC0329LongestIncreasingPathInAMatrix::longestIncreasingPath(matrix));
}

TEST(leetcode, LC0329LongestIncreasingPathInAMatrix_Testcase3) {
    std::vector<std::vector<int>> matrix = {{1}};
    ASSERT_EQ(1, LC0329LongestIncreasingPathInAMatrix::longestIncreasingPath(matrix));
}
