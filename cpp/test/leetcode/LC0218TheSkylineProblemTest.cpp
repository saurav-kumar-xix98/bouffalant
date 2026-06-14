#include <gtest/gtest.h>

#include "leetcode/LC0218TheSkylineProblem.hpp"

TEST(leetcode, LC0218TheSkylineProblem_Testcase1) {
    const std::vector<std::vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    const std::vector<std::vector<int>> expectedOutput = {{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}};
    EXPECT_EQ(expectedOutput, LC0218TheSkylineProblem::getSkyline(buildings));
}

TEST(leetcode, LC0218TheSkylineProblem_Testcase2) {
    const std::vector<std::vector<int>> buildings = {{0,2,3},{2,5,3}};
    const std::vector<std::vector<int>> expectedOutput = {{0,3},{5,0}};
    EXPECT_EQ(expectedOutput, LC0218TheSkylineProblem::getSkyline(buildings));
}
