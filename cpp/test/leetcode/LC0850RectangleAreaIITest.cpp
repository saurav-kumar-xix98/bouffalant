#include <gtest/gtest.h>

#include "leetcode/LC0850RectangleAreaII.hpp"

TEST(leetcode, LC0850RectangleAreaII_Testcase1) {
    const std::vector<std::vector<int>> rectangles = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    ASSERT_EQ(6, LC0850RectangleAreaII::rectangleArea(rectangles));
}

TEST(leetcode, LC0850RectangleAreaII_Testcase2) {
    const std::vector<std::vector<int>> rectangles = {{0,0,1000000000,1000000000}};
    ASSERT_EQ(49, LC0850RectangleAreaII::rectangleArea(rectangles));
}
