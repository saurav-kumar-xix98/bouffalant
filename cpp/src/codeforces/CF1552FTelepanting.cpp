#include "codeforces/CF1552FTelepanting.hpp"

#include "util.hpp"

#include <vector>

int32_t CF1552FTelepanting::telepanting(const std::vector<int32_t>& src, const std::vector<int32_t>& des, const std::vector<bool>& state) {
    constexpr uint32_t divisor = 998244353;
    const size_t N = src.size();

    std::vector<int64_t> prefixSum(N + 1);
    prefixSum[0] = 0;
    for (size_t i = 0; i < N; ++i) {
        const size_t index = std::lower_bound(src.begin(), src.begin() + i, des[i]) - src.begin();

        prefixSum[i + 1] = util::modulus<divisor>(
            prefixSum[i]
            + static_cast<int64_t>(src[i]) - static_cast<int64_t>(des[i])
            + prefixSum[i] - prefixSum[index]
        );
    }

    int64_t ans = util::modulus<divisor>(src.back() + 1);

    for (size_t i = 0; i < N; ++i) {
        if (state[i]) {
            ans = util::modulus<divisor>(ans + prefixSum[i + 1] - prefixSum[i]);
        }
    }

    return static_cast<int32_t>(util::modulus<divisor>(ans));
}
