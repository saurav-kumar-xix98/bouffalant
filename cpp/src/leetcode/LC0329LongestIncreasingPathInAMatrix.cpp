#include "leetcode/LC0329LongestIncreasingPathInAMatrix.hpp"

namespace {
    int computeLongestPath(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &counts, size_t r, size_t c);
}

int LC0329LongestIncreasingPathInAMatrix::longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    const size_t R = matrix.size(), C = matrix[0].size();
    std::vector counts(R, std::vector(C, 0));
    int ans = 0;
    for (size_t r = 0; r < R; ++r) {
        for (size_t c = 0; c < C; ++c) {
            ans = std::max(ans, computeLongestPath(matrix, counts, r, c));
        }
    }
    return ans;
}

namespace {
    int computeLongestPath(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &counts, const size_t r, const size_t c) {
        if (counts[r][c] != 0) {
            return counts[r][c];
        }

        counts[r][c] = 1;

        const size_t R = matrix.size(), C = matrix[0].size();

        if (r > 0 && matrix[r][c] < matrix[r - 1][c]) {
            counts[r][c] = std::max(counts[r][c], 1 + computeLongestPath(matrix, counts, r - 1, c));
        }
        if (r < R - 1 && matrix[r][c] < matrix[r + 1][c]) {
            counts[r][c] = std::max(counts[r][c], 1 + computeLongestPath(matrix, counts, r + 1, c));
        }
        if (c > 0 && matrix[r][c] < matrix[r][c - 1]) {
            counts[r][c] = std::max(counts[r][c], 1 + computeLongestPath(matrix, counts, r, c - 1));
        }
        if (c < C - 1 && matrix[r][c] < matrix[r][c + 1]) {
            counts[r][c] = std::max(counts[r][c], 1 + computeLongestPath(matrix, counts, r, c + 1));
        }
        return counts[r][c];
    }
}
