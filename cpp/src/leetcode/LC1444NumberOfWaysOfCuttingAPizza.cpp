#include "leetcode/LC1444NumberOfWaysOfCuttingAPizza.hpp"

namespace {
    std::vector<std::vector<int>> countApples(const std::vector<std::string> &pizza);
    int countWays(const std::vector<std::vector<int>> &apples, std::vector<std::vector<std::vector<int>>> &dpLookup, size_t r, size_t c, size_t k);
}

int LC1444NumberOfWaysOfCuttingAPizza::ways(const std::vector<std::string>& pizza, const int k) {
    const auto apples = countApples(pizza);
    const size_t rows = apples.size(), cols = apples[0].size(), cuts = k;
    std::vector dpLookup(rows, std::vector(cols, std::vector(cuts, -1)));
    return countWays(apples, dpLookup, 0, 0, 0);
}

namespace {
    std::vector<std::vector<int>> countApples(const std::vector<std::string> &pizza) {
        const size_t rows = pizza.size(), cols = pizza[0].size();

        std::vector apples(rows, std::vector(cols, 0));

        for (size_t r = rows; r > 0;) {
            --r;
            for (size_t c = cols; c > 0;) {
                --c;
                apples[r][c] = (pizza[r][c] == 'A' ? 1 : 0)
                + (r + 1 < rows ? apples[r + 1][c] : 0)
                + (c + 1 < cols ? apples[r][c + 1] : 0)
                - (r + 1 < rows && c + 1 < cols ? apples[r + 1][c + 1] : 0);
            }
        }
        return apples;
    }

    constexpr int MOD = 1'000'000'007;

    int countWays(const std::vector<std::vector<int>> &apples, std::vector<std::vector<std::vector<int>>> &dpLookup, const size_t r, const size_t c, const size_t k) {
        int &result = dpLookup[r][c][k];
        if (result != -1) {
            return result;
        }

        const size_t rows = dpLookup.size(), cols = dpLookup[0].size(), cuts = dpLookup[0][0].size();
        if (k == cuts - 1) {
            result = apples[r][c] != 0 ? 1 : 0;
            return result;
        }

        long long counts = 0;
        for (size_t r2 = r + 1; r2 < rows; ++r2) {
            if (apples[r][c] - apples[r2][c] > 0) {
                counts += countWays(apples, dpLookup, r2, c, k + 1);
                counts %= MOD;
            }
        }
        for (size_t c2 = c + 1; c2 < cols; ++c2) {
            if (apples[r][c] - apples[r][c2] > 0) {
                counts += countWays(apples, dpLookup, r, c2, k + 1);
                counts %= MOD;
            }
        }
        result = static_cast<int>(counts);
        return result;
    }
}
