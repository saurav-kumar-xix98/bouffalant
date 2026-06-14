#include <gtest/gtest.h>

#include "leetcode/LC1610MaximumNumberOfVisiblePoints.hpp"

TEST(leetcode, LC1610MaximumNumberOfVisiblePoints_Testcase1) {
    const std::vector<std::vector<int>> points = {{2,1},{2,2},{3,3}};
    const std::vector location = {1, 1};
    ASSERT_EQ(3, LC1610MaximumNumberOfVisiblePoints::visiblePoints(points, 90, location));
}

TEST(leetcode, LC1610MaximumNumberOfVisiblePoints_Testcase2) {
    const std::vector<std::vector<int>> points = {{2,1},{2,2},{3,4},{1,1}};
    const std::vector location = {1, 1};
    ASSERT_EQ(4, LC1610MaximumNumberOfVisiblePoints::visiblePoints(points, 90, location));
}

TEST(leetcode, LC1610MaximumNumberOfVisiblePoints_Testcase3) {
    const std::vector<std::vector<int>> points = {{1,0},{2,1}};
    const std::vector location = {1, 1};
    ASSERT_EQ(1, LC1610MaximumNumberOfVisiblePoints::visiblePoints(points, 13, location));
}
