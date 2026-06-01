#include <gtest/gtest.h>

#include "codeforces/CF1552FTelepanting.hpp"

TEST(codeforces, CF1552FTelepanting_Testcase1) {
    const std::vector src = { 3, 6, 7, 8 };
    const std::vector des = { 2, 5, 4, 1 };
    const std::vector state = { false, true, false, true };

    ASSERT_EQ(23, CF1552FTelepanting::telepanting(src, des, state));
}

TEST(codeforces, CF1552FTelepanting_Testcase2) {
    const std::vector src = { 454971987 };
    const std::vector des = { 406874902 };
    const std::vector state = { true };

    ASSERT_EQ(503069073, CF1552FTelepanting::telepanting(src, des, state));
}

TEST(codeforces, CF1552FTelepanting_Testcase3) {
    const std::vector src = {243385510, 644426565, 708622105, 786625660, 899754846};
    const std::vector des = {42245605, 574769163, 208990040, 616437691, 382774619};
    const std::vector state = { false, false, false, false, false };

    ASSERT_EQ(899754847, CF1552FTelepanting::telepanting(src, des, state));
}

TEST(codeforces, CF1552FTelepanting_Testcase4) {
    const std::vector src = {200000000, 600000000, 800000000, 900000000, 1000000000};
    const std::vector des = { 100000000, 400000000, 300000000, 700000000, 500000000 };
    const std::vector state = { true, false, false, true, false };

    ASSERT_EQ(3511295, CF1552FTelepanting::telepanting(src, des, state));
}
