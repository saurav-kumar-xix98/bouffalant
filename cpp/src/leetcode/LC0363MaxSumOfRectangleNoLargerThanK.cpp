#include "leetcode/LC0363MaxSumOfRectangleNoLargerThanK.hpp"

#include <limits>
#include <set>

namespace {
    void buildPrefixSum(std::vector<std::vector<int>>& matrix);
}

int LC0363MaxSumOfRectangleNoLargerThanK::maxSumSubmatrix(std::vector<std::vector<int>>& matrix, const int k) {
    buildPrefixSum(matrix);
    const size_t R = matrix.size(), C = matrix[0].size();
    int best = std::numeric_limits<int>::min();
    for (size_t r1 = 0; r1 < R; ++r1) {
        for (size_t r2 = r1; r2 < R; ++r2) {
            std::set seenSums = { 0 };
            for (size_t c = 0; c < C; ++c) {
                int sum = matrix[r2][c] - (r1 > 0 ? matrix[r1 - 1][c] : 0);
                if (auto itr = seenSums.lower_bound(sum - k); itr != seenSums.end()) {
                    best = std::max(best, sum - *itr);
                }
                seenSums.insert(sum);
            }
        }
    }
    return best;
}

namespace {
    void buildPrefixSum(std::vector<std::vector<int>>& matrix) {
        const size_t R = matrix.size(), C = matrix[0].size();
        for (size_t r = 1; r < R; ++r) {
            matrix[r][0] += matrix[r - 1][0];
        }
        for (size_t c = 1; c < C; ++c) {
            matrix[0][c] += matrix[0][c - 1];
        }
        for (size_t r = 1; r < R; ++r) {
            for (size_t c = 1; c < C; ++c) {
                matrix[r][c] += matrix[r - 1][c] + matrix[r][c - 1] - matrix[r - 1][c - 1];
            }
        }
    }
}
