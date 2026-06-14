#include <gtest/gtest.h>

#include "leetcode/LC0315CountOfSmallerNumbersAfterSelf.hpp"

TEST(leetcode, LC0315CountOfSmallerNumbersAfterSelf_Testcase1) {
    const std::vector nums = {5,2,6,1};
    const std::vector expected = {2,1,1,0};
    ASSERT_EQ(expected, LC0315CountOfSmallerNumbersAfterSelf::countSmaller(nums));
}

TEST(leetcode, LC0315CountOfSmallerNumbersAfterSelf_Testcase2) {
    const std::vector nums = {-1};
    const std::vector expected = {0};
    ASSERT_EQ(expected, LC0315CountOfSmallerNumbersAfterSelf::countSmaller(nums));
}

TEST(leetcode, LC0315CountOfSmallerNumbersAfterSelf_Testcase3) {
    const std::vector nums = {-1,-1};
    const std::vector expected = {0,0};
    ASSERT_EQ(expected, LC0315CountOfSmallerNumbersAfterSelf::countSmaller(nums));
}
