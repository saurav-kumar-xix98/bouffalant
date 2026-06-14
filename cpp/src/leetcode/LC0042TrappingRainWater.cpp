#include "leetcode/LC0042TrappingRainWater.hpp"

#include <algorithm>

int LC0042TrappingRainWater::trap(const std::vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int h = 0;
    int w = 0;
    while (l <= r) {
        if (const int h2 = std::min(height[l], height[r]);
            h2 > h) {

            w += (h2 - h) * (r - l + 1);
            h = h2;
            }

        if (height[l] <= height[r]) {
            w -= height[l++];
        } else {
            w -= height[r--];
        }
    }
    return w;
}
