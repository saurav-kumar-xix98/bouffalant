#include <gtest/gtest.h>

#include "leetcode/LC0857MinimumCostToHireKWorkers.hpp"

TEST(leetcode, LC0857MinimumCostToHireKWorkers_Testcase1) {
    const std::vector quality = {10,20,5};
    const std::vector wage = {70,50,30};
    ASSERT_NEAR(105.00000, LC0857MinimumCostToHireKWorkers::mincostToHireWorkers(quality, wage, 2), 1e-5);
}

TEST(leetcode, LC0857MinimumCostToHireKWorkers_Testcase2) {
    const std::vector quality = {3,1,10,10,1};
    const std::vector wage = {4,8,2,2,7};
    ASSERT_NEAR(30.66667, LC0857MinimumCostToHireKWorkers::mincostToHireWorkers(quality, wage, 3), 1e-5);
}
