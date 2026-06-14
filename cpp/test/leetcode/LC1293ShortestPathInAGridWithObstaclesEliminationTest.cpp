#include <gtest/gtest.h>

#include "leetcode/LC1293ShortestPathInAGridWithObstaclesElimination.hpp"

TEST(leetcode, LC1293ShortestPathInAGridWithObstaclesElimination_Testcase1) {
    const std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    constexpr int k = 1;
    constexpr int expected = 6;
    EXPECT_EQ(expected, LC1293ShortestPathInAGridWithObstaclesElimination::shortestPath(grid, k));
}

TEST(leetcode, LC1293ShortestPathInAGridWithObstaclesElimination_Testcase2) {
    const std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}};
    constexpr int k = 1;
    constexpr int expected = -1;
    EXPECT_EQ(expected, LC1293ShortestPathInAGridWithObstaclesElimination::shortestPath(grid, k));
}
