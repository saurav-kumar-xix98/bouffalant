#include "leetcode/LC0803BricksFallingWhenHit.hpp"

namespace {
    class DSU {
        std::vector<size_t> parents;
        std::vector<int> counts;
        const size_t R;
        const size_t C;
    public:
        DSU(size_t R, size_t C);
        void addCell(size_t r, size_t c);
        [[nodiscard]] int getStableCount() const;
    private:
        void merge(size_t i1, size_t i2);
    };
}

std::vector<int> LC0803BricksFallingWhenHit::hitBricks(std::vector<std::vector<int>>& grid, const std::vector<std::vector<int>>& hits) {
    const size_t R = grid.size();
    const size_t C = grid[0].size();
    for (const auto &hit : hits) {
        const size_t r = hit[0];
        const size_t c = hit[1];
        grid[r][c]--;
    }
    DSU dsu(R, C);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] != 1)
                continue;
            dsu.addCell(r,c);
        }
    }

    std::vector result(hits.size(), 0);

    for (size_t i = hits.size(); i > 0;) {
        i--;
        const size_t r = hits[i][0];
        const size_t c = hits[i][1];
        grid[r][c]++;
        if (grid[r][c] != 1)
            continue;
        const int oldStableCount = dsu.getStableCount();
        dsu.addCell(r, c);
        if (const int newStableCount = dsu.getStableCount();
            oldStableCount != newStableCount)
            result[i] = newStableCount - oldStableCount - 1;
    }

    return result;
}

namespace {
    DSU::DSU(const size_t R, const size_t C) : R(R), C(C) {
        parents = std::vector(R * C + 1, static_cast<size_t>(0));
        counts = std::vector(R * C + 1, 0);
    }

    void DSU::addCell(const size_t r, const size_t c) {
        const size_t i = r * C + c + 1;
        counts[i] = 1;
        parents[i] = i;
        if (r == 0)
            merge(0, i);
        if (r > 0) {
            if (const size_t i2 = (r - 1) * C + c + 1;
                counts[i2] != 0) {
                merge(i, i2);
                }
        }
        if (c > 0) {
            if (const size_t i2 = r * C + c;
                counts[i2] != 0) {
                merge(i, i2);
                }
        }
        if (r < R - 1) {
            if (const size_t i2 = (r + 1) * C + c + 1;
                counts[i2] != 0) {
                merge(i, i2);
                }
        }
        if (c < C - 1) {
            if (const size_t i2 = r * C + c + 2;
                counts[i2] != 0) {
                merge(i, i2);
                }
        }
    }

    int DSU::getStableCount() const {
        return counts[0];
    }

    void DSU::merge(const size_t i1, const size_t i2) {
        size_t p1 = parents[i1], p2 = parents[i2];
        while (parents[p1] != p1) {
            p1 = parents[p1];
        }
        while (parents[p2] != p2) {
            p2 = parents[p2];
        }
        if (p1 == p2) {
            return;
        }
        if (p1 < p2) {
            parents[p2] = p1;
            counts[p1] += counts[p2];
        } else {
            parents[p1] = p2;
            counts[p2] += counts[p1];
        }
    }
}
