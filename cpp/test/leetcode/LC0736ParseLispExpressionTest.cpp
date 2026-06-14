#include <gtest/gtest.h>

#include "leetcode/LC0736ParseLispExpression.hpp"

TEST(leetcode, LC0736ParseLispExpression_Testcase1) {
    ASSERT_EQ(14, LC0736ParseLispExpression::evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"));
}

TEST(leetcode, LC0736ParseLispExpression_Testcase2) {
    ASSERT_EQ(2, LC0736ParseLispExpression::evaluate("(let x 3 x 2 x)"));
}

TEST(leetcode, LC0736ParseLispExpression_Testcase3) {
    ASSERT_EQ(5, LC0736ParseLispExpression::evaluate("(let x 1 y 2 x (add x y) (add x y))"));
}
