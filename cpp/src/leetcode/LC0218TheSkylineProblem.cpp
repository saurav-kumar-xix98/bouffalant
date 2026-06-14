#include "leetcode/LC0218TheSkylineProblem.hpp"


#include <queue>
#include <set>

std::vector<std::vector<int>> LC0218TheSkylineProblem::getSkyline(const std::vector<std::vector<int>>& buildings) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> edges;
    for (const auto &b : buildings) {
        edges.emplace(b[0], -b[2]);
        edges.emplace(b[1], b[2]);
    }

    std::multiset heights =  {0};
    std::vector<std::vector<int>> result;
    int prevHeight = 0;

    while (!edges.empty()) {
        const auto [position, height] = edges.top();
        edges.pop();
        if (height < 0) {
            heights.insert(-height);
        } else {
            heights.erase(heights.find(height));
        }

        if (int currHeight = *heights.rbegin();
            currHeight != prevHeight) {
            result.push_back({position, currHeight});
            prevHeight = currHeight;
            }
    }

    return result;
}
