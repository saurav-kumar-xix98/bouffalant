#include "leetcode/LC0410SplitArrayLargestSum.hpp"

#include <algorithm>

namespace {
    int countSubarrays(const std::vector<int> &nums, int candidateSum);
}

int LC0410SplitArrayLargestSum::splitArray(const std::vector<int>& nums, const int k) {
    int minLargestSum = nums[0];
    int maxLargestSum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        minLargestSum = std::max(minLargestSum, nums[i]);
        maxLargestSum += nums[i];
    }
    while (minLargestSum < maxLargestSum) {
        if (const int candidateSum = (minLargestSum + maxLargestSum) / 2;
            countSubarrays(nums, candidateSum) > k) {
            minLargestSum = candidateSum + 1;
            } else {
                maxLargestSum = candidateSum;
            }
    }
    return minLargestSum;
}

namespace {
    int countSubarrays(const std::vector<int> &nums, const int candidateSum) {
        int count = 1;
        int runningSum = 0;
        for (const int num : nums) {
            if (runningSum + num > candidateSum) {
                runningSum = 0;
                count++;
            }
            runningSum += num;
        }
        return count;
    }
}
