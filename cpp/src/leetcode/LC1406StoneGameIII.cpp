#include "leetcode/LC1406StoneGameIII.hpp"

#include <limits>

namespace {
    int dp(int pos, const std::vector<int> &stoneValue, std::vector<int> &memo);
}

std::string LC1406StoneGameIII::stoneGameIII(const std::vector<int>& stoneValue) {
    std::vector memo(stoneValue.size(), std::numeric_limits<int>::min());
    const int diff = dp(0, stoneValue, memo);
    if (diff > 0) {
        return "Alice";
    }
    if (diff < 0) {
        return "Bob";
    }
    return "Tie";
}

namespace {
    int dp(const int pos, const std::vector<int> &stoneValue, std::vector<int> &memo) {
        if (pos >= stoneValue.size())   {
            return 0;
        }
        if (memo[pos] != std::numeric_limits<int>::min()) {
            return memo[pos];
        }
        int best = std::numeric_limits<int>::min();
        int sum = 0;
        for (int i = pos; i < pos + 3 && i < stoneValue.size(); ++i) {
            sum += stoneValue[i];
            best = std::max(best, sum - dp(i + 1, stoneValue, memo));
        }
        memo[pos] = best;
        return best;
    }
}
