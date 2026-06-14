#include "leetcode/LC1610MaximumNumberOfVisiblePoints.hpp"

#include <cmath>
#include <algorithm>

int LC1610MaximumNumberOfVisiblePoints::visiblePoints(const std::vector<std::vector<int>>& points, const int angle, const std::vector<int>& location) {
    std::vector<double> angles;
    int base = 0;
    for (auto & point : points) {
        if (point[0] == location[0] && point[1] == location[1]) {
            base++;
            continue;
        }
        const double x = point[0] - location[0];
        const double y = point[1] - location[1];
        double ang = std::atan2(y,x) * 180.0 / M_PI;
        angles.push_back(ang);
    }
    std::ranges::sort(angles);
    const size_t n = angles.size();
    angles.resize(n * 2);
    for (size_t i = 0; i < n; ++i) {
        angles[n + i] = angles[i] + 360;
    }
    int result = base;
    int l, r;
    for (l = 0, r = 0; l < n; ++l) {
        while (r < angles.size() && angles[r] - angles[l] <= angle + 1e-9) {
            r++;
        }
        result = std::max(result, base + r - l);
    }
    return result;
}
