#include <gtest/gtest.h>

#include "leetcode/LC0803BricksFallingWhenHit.hpp"

TEST(leetcode, LC0803BricksFallingWhenHit_Testcase1) {
    std::vector<std::vector<int>> grid = {{1,0,0,0},{1,1,1,0}};
    const std::vector<std::vector<int>> hits = {{1,0}};
    const std::vector expected = {2};
    ASSERT_EQ(expected, LC0803BricksFallingWhenHit::hitBricks(grid, hits));
}

TEST(leetcode, LC0803BricksFallingWhenHit_Testcase2) {
    std::vector<std::vector<int>> grid = {{1,0,0,0},{1,1,0,0}};
    const std::vector<std::vector<int>> hits = {{1,1},{1,0}};
    const std::vector expected = {0,0};
    ASSERT_EQ(expected, LC0803BricksFallingWhenHit::hitBricks(grid, hits));
}
