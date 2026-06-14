#include "leetcode/LC067924Game.hpp"

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <unordered_set>

namespace {
    std::pair<int, int> normalise(std::pair<int, int> fraction);

    template <typename T1, typename T2>
    struct PairHash {
        size_t operator()(const std::pair<T1, T2>& p) const;
    };
}

bool LC067924Game::judgePoint24(const std::vector<int>& cards) {
    const auto n = 1 << cards.size();

    std::vector<std::unordered_set<std::pair<int, int>, PairHash<int, int>>> possibleResults(n);

    for (size_t i = 0; i < cards.size(); ++i) {
        possibleResults[1 << i].insert({cards[i], 1});
    }

    for (size_t mask = 3; mask < n; ++mask) {

        for (size_t submask = 1; submask < mask; ++submask) {

            if ((mask & submask) != submask) {
                continue;
            }

            const size_t complement = mask ^ submask;

            if (complement < submask) {
                continue;
            }

            for (const auto lhs : possibleResults[submask]) {
                for (const auto rhs : possibleResults[complement]) {

                    auto [a, b] = lhs;
                    auto [c, d] = rhs;

                    possibleResults[mask].insert(normalise({a * d + c * b, b * d}));

                    possibleResults[mask].insert(normalise({a * d - c * b, b * d}));
                    possibleResults[mask].insert(normalise({c * b - a * d, b * d}));

                    possibleResults[mask].insert(normalise({a * c, b * d}));

                    if (c != 0) {
                        possibleResults[mask].insert(normalise({a * d, b * c}));
                    }
                    if (a != 0) {
                        possibleResults[mask].insert(normalise({b * c, a * d}));
                    }
                }
            }
        }
    }

    return possibleResults.back().contains({24, 1});
}

namespace {

    std::pair<int, int> normalise(std::pair<int, int> fraction) {
        auto [a, b] = fraction;
        const int factor = std::gcd(std::abs(a), std::abs(b));

        a /= factor;
        b /= factor;

        if (b < 0) {
            a = -a;
            b = -b;
        }

        return {a, b};
    }

    template <typename T1, typename T2>
    size_t PairHash<T1, T2>::operator()(const std::pair<T1, T2>& p) const {
        const auto hash1 = std::hash<T1>{}(p.first);
        const auto hash2 = std::hash<T2>{}(p.second);

        return hash1 ^ (hash2 << 4);
    }
}
