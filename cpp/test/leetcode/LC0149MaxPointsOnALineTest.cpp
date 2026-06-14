#include <gtest/gtest.h>

#include "leetcode/LC0149MaxPointsOnALine.hpp"

TEST(leetcode, LC0149MaxPointsOnALine_Testcase1) {
    const std::vector<std::vector<int>> points = {{1,1},{2,2},{3,3}};
    ASSERT_EQ(3, LC0149MaxPointsOnALine::maxPoints(points));
}

TEST(leetcode, LC0149MaxPointsOnALine_Testcase2) {
    const std::vector<std::vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    ASSERT_EQ(4, LC0149MaxPointsOnALine::maxPoints(points));
}
