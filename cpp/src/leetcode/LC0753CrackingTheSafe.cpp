#include "leetcode/LC0753CrackingTheSafe.hpp"

#include <vector>

namespace {
    int power(int base, int exp);

    bool dfs(
        int start,
        std::vector<bool> &visited,
        std::string& result,
        int remaining,
        int k,
        int base
    );
}

std::string LC0753CrackingTheSafe::crackSafe(const int n, const int k) {
    const int count = power(k, n);
    std::vector visited(count, false);
    visited[0] = true;

    const int base = power(k, n - 1);
    std::string result(n, '0');

    dfs(0, visited, result, count - 1, k, base);

    return result;
}

namespace {

    int power(int base, int exp) {
        int res = 1;

        while (exp > 0) {
            if (exp & 1) {
                res *= base;
            }

            base *= base;
            exp >>= 1;
        }

        return res;
    }

    bool dfs(
        const int start,
        std::vector<bool> &visited,
        std::string& result,
        const int remaining,
        const int k,
        const int base
    ) {
        if (remaining == 0) {
            return true;
        }

        for (int i = 0; i < k; i++) {

            const int next = (start % base) * k + i;
            if (visited[next]) {
                continue;
            }

            visited[next] = true;
            result.push_back(i + '0');

            if (dfs(next, visited, result, remaining - 1, k, base)) {
                return true;
            }

            result.pop_back();
            visited[next] = false;
        }

        return false;
    }

}
