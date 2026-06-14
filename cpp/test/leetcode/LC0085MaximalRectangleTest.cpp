#include <gtest/gtest.h>

#include "leetcode/LC0085MaximalRectangle.hpp"

TEST(leetcode, LC0085MaximalRectangle_Testcase1) {
    const std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    ASSERT_EQ(6, LC0085MaximalRectangle::maximalRectangle(matrix));
}

TEST(leetcode, LC0085MaximalRectangle_Testcase2) {
    const std::vector<std::vector<char>> matrix = {{'0'}};
    ASSERT_EQ(0, LC0085MaximalRectangle::maximalRectangle(matrix));
}

TEST(leetcode, LC0085MaximalRectangle_Testcase3) {
    const std::vector<std::vector<char>> matrix = {{'1'}};
    ASSERT_EQ(1, LC0085MaximalRectangle::maximalRectangle(matrix));
}
