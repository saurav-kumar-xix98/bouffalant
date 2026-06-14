#include <gtest/gtest.h>

#include "leetcode/LC1444NumberOfWaysOfCuttingAPizza.hpp"

TEST(leetcode, LC1444NumberOfWaysOfCuttingAPizza_Testcase1) {
    const std::vector<std::string> pizza = {"A..","AAA","..."};
    ASSERT_EQ(3, LC1444NumberOfWaysOfCuttingAPizza::ways(pizza, 3));
}

TEST(leetcode, LC1444NumberOfWaysOfCuttingAPizza_Testcase2) {
    const std::vector<std::string> pizza = {"A..","AA.","..."};
    ASSERT_EQ(1, LC1444NumberOfWaysOfCuttingAPizza::ways(pizza, 3));
}

TEST(leetcode, LC1444NumberOfWaysOfCuttingAPizza_Testcase3) {
    const std::vector<std::string> pizza = {"A..","A..","..."};
    ASSERT_EQ(1, LC1444NumberOfWaysOfCuttingAPizza::ways(pizza, 1));
}
