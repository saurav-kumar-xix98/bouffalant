#include "leetcode/LC0857MinimumCostToHireKWorkers.hpp"

#include <algorithm>
#include <queue>
#include <numeric>

double LC0857MinimumCostToHireKWorkers::mincostToHireWorkers(const std::vector<int>& quality, const std::vector<int>& wage, const int k) {
    const size_t n = quality.size();
    std::vector<double> wageQualityRatio(n);
    for (size_t i = 0; i < n; ++i) {
        wageQualityRatio[i] = static_cast<double>(wage[i]) / static_cast<double>(quality[i]);
    }
    std::vector<size_t> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::ranges::sort(indices, [&](const size_t l, const size_t r) {
        if (wageQualityRatio[l] == wageQualityRatio[r]) {
            return wage[l] < wage[r];
        }
        return wageQualityRatio[l] < wageQualityRatio[r];
    });

    double ans = std::numeric_limits<double>::max();
    std::priority_queue<int> selectedQualities;
    int cumulativeQuality = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t index = indices[i];
        cumulativeQuality += quality[index];
        selectedQualities.push(quality[index]);
        if (selectedQualities.size() < k) {
            continue;
        }
        while (selectedQualities.size() > k) {
            cumulativeQuality -= selectedQualities.top();
            selectedQualities.pop();
        }
        ans = std::min(ans, cumulativeQuality * wageQualityRatio[index]);
    }
    return ans;
}
