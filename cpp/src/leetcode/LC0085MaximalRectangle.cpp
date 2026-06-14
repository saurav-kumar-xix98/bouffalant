#include "leetcode/LC0085MaximalRectangle.hpp"

int LC0085MaximalRectangle::maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    const int R = matrix.size(), C = matrix[0].size();
    std::vector prefix(R, std::vector(C, 0));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (matrix[r][c] == '0')
                continue;
            prefix[r][c] = 1 + (r > 0 ? prefix[r - 1][c] : 0);
        }
    }
    std::vector<std::vector<int>> left(R, std::vector(C, -1)), right(R, std::vector(C, C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            {
                int i = c - 1;
                while (i >= 0) {
                    if (prefix[r][i] < prefix[r][c])
                        break;
                    i = left[r][i];
                }
                left[r][c] = i;
            }
            {
                int i = C - c;
                while (i < C) {
                    if (prefix[r][i] < prefix[r][C - 1 - c])
                        break;
                    i = right[r][i];
                }
                right[r][C - 1 - c] = i;
            }
        }
    }
    int ans = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            ans = std::max(ans, prefix[r][c] * (right[r][c] - left[r][c] - 1));
        }
    }
    return ans;
}
