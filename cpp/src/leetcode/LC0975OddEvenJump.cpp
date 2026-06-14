#include "leetcode/LC0975OddEvenJump.hpp"

#include <map>

int LC0975OddEvenJump::oddEvenJumps(const std::vector<int>& arr) {
    const size_t N = arr.size();
    std::vector isOddJumpPossible(N, false);
    std::vector isEvenJumpPossible(N, false);

    isOddJumpPossible[N - 1] = true;
    isEvenJumpPossible[N - 1] = true;

    std::map<int, size_t> numIndexMap;
    numIndexMap[arr[N - 1]] = N - 1;

    int count = 1;

    for (size_t i = N - 2; i < N; i--) {
        if (auto itr = numIndexMap.lower_bound(arr[i]); itr != numIndexMap.end()) {
            const size_t j = itr->second;

            isOddJumpPossible[i] = isEvenJumpPossible[j];
            if (isOddJumpPossible[i]) {
                count++;
            }
        }

        if (auto itr = numIndexMap.upper_bound(arr[i]); itr != numIndexMap.begin()) {
            --itr;
            const size_t j = itr->second;

            isEvenJumpPossible[i] = isOddJumpPossible[j];
        }

        numIndexMap[arr[i]] = i;
    }

    return count;
}
