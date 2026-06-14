#include <gtest/gtest.h>

#include "leetcode/LC0753CrackingTheSafe.hpp"

bool validateRecursive(const std::string &result, std::string &pass, const int n, const int k) {
    if (n == 0) {
        return result.contains(pass);
    }
    for (int i = 0; i < k; i++) {
        pass.push_back(i + '0');
        if (!validateRecursive(result, pass, n - 1, k)) {
            return false;
        }
        pass.pop_back();
    }
    return true;
}

bool validate(const std::string &result, const int n, const int k) {
    std::string pass;
    return validateRecursive(result, pass, n, k);
}

TEST(leetcode, LC0753CrackingTheSafe_Testcase1) {
    constexpr int n = 1;
    constexpr int k = 2;
    const std::string result = LC0753CrackingTheSafe::crackSafe(n, k);
    ASSERT_TRUE(validate(result, n, k));
}

TEST(leetcode, LC0753CrackingTheSafe_Testcase2) {
    constexpr int n = 2;
    constexpr int k = 2;
    const std::string result = LC0753CrackingTheSafe::crackSafe(n, k);
    ASSERT_TRUE(validate(result, n, k));
}
