#include "leetcode/LC1293ShortestPathInAGridWithObstaclesElimination.hpp"

#include <array>

int LC1293ShortestPathInAGridWithObstaclesElimination::shortestPath(const std::vector<std::vector<int>>& grid, const int K) {
    const int R = grid.size(), C = grid[0].size();
    if (K - grid[0][0] >= R + C - 2) {
        return R + C - 2;
    }
    std::vector markedToVisit(R, std::vector(C, std::vector(K + 1, false)));
    std::vector<std::array<int, 3>> bfsNodes;
    markedToVisit[0][0][K - grid[0][0]] = true;
    bfsNodes.push_back({ 0, 0, K - grid[0][0] });
    int stepCount = 0;
    while (!bfsNodes.empty()) {
        stepCount++;
        std::vector<std::array<int, 3>> nextBfsNodes;
        for (const auto &node : bfsNodes) {
            const int r = node[0], c = node[1], k = node[2];
            static const std::vector<std::pair<int, int>> offsets = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [rOff, cOff] : offsets) {
                const int r2 = r + rOff, c2 = c + cOff;
                if (r2 == R - 1 && c2 == C - 1) {
                    return stepCount;
                }
                if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C || k - grid[r2][c2] < 0) {
                    continue;
                }
                if (markedToVisit[r2][c2][k - grid[r2][c2]]) {
                    continue;
                }
                markedToVisit[r2][c2][k - grid[r2][c2]] = true;
                nextBfsNodes.push_back({ r2, c2, k - grid[r2][c2] });
            }
        }
        bfsNodes.swap(nextBfsNodes);
    }
    return -1;
}
