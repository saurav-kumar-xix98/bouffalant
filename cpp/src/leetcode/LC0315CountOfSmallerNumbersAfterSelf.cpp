#include "leetcode/LC0315CountOfSmallerNumbersAfterSelf.hpp"

#include <numeric>

namespace {
    void mergeSort(const std::vector<int> &nums, std::vector<size_t> &indices, std::vector<int> &counts, size_t start, size_t end);
}

std::vector<int> LC0315CountOfSmallerNumbersAfterSelf::countSmaller(const std::vector<int>& nums) {
    const size_t n = nums.size();
    std::vector<size_t> indices(n);
    std::vector counts(n, 0);
    std::iota(indices.begin(), indices.end(), 0);
    mergeSort(nums, indices, counts, 0, n);
    return counts;
}

namespace {
    void merge(const std::vector<int> &nums, std::vector<size_t> &indices, std::vector<int> &counts, const size_t start, const size_t end) {
        const size_t mid = (start + end) / 2;
        size_t bufferIndex = 0, leftIndex = start, rightIndex = mid;
        std::vector<size_t> buffer(end - start);

        while (leftIndex < mid && rightIndex < end) {
            if (nums[indices[leftIndex]] <= nums[indices[rightIndex]]) {
                counts[indices[leftIndex]] += static_cast<int>(rightIndex - mid);
                buffer[bufferIndex++] = indices[leftIndex++];
            } else {
                buffer[bufferIndex++] = indices[rightIndex++];
            }
        }

        while (leftIndex < mid) {
            counts[indices[leftIndex]] += static_cast<int>(rightIndex - mid);
            buffer[bufferIndex++] = indices[leftIndex++];
        }
        while (rightIndex < end) {
            buffer[bufferIndex++] = indices[rightIndex++];
        }

        for (size_t j = start; j < end; ++j) {
            indices[j] = buffer[j - start];
        }
    }

    void mergeSort(const std::vector<int> &nums, std::vector<size_t> &indices, std::vector<int> &counts, const size_t start, const size_t end) {
        if (end - start == 1)
            return;
        const size_t mid = (start + end) / 2;
        mergeSort(nums, indices, counts, start, mid);
        mergeSort(nums, indices, counts, mid, end);
        merge(nums, indices, counts, start, end);
    }
}
