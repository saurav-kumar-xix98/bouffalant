#include "leetcode/LC0149MaxPointsOnALine.hpp"

#include <cmath>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <unordered_set>

namespace {
    using Point = std::pair<int, int>;

    std::pair<int, int> normalise(int a, int b);

    struct Line {
        int a, b, c;
        bool operator==(const Line& other) const;
        static Line fromPoints(const Point& p1, const Point& p2);
    };

    struct LineHasher {
        size_t operator()(const Line& line) const;
    };
}

int LC0149MaxPointsOnALine::maxPoints(const std::vector<std::vector<int>>& points) {
    if (points.size() <= 2) {
        return static_cast<int>(points.size());
    }

    std::unordered_map<Line, int, LineHasher> lineCounts;
    for (int i = 0; i < points.size(); ++i) {
        std::unordered_set<Line, LineHasher> newLinesFromThisPoint;
        Point p1 = {points[i][0], points[i][1]};
        for (int j = i + 1; j < points.size(); ++j) {
            Point p2 = {points[j][0], points[j][1]};

            if (const Line line = Line::fromPoints(p1, p2); !lineCounts.contains(line)) {
                lineCounts[line] = 2;
                newLinesFromThisPoint.insert(line);
            } else if (newLinesFromThisPoint.contains(line)) {
                lineCounts[line]++;
            }
        }
    }
    int maxPoints = 0;
    for (const auto& count : lineCounts | std::views::values) {
        maxPoints = std::max(maxPoints, count);
    }
    return maxPoints;
}

namespace {
    std::pair<int, int> normalise(int a, int b) {
        const int divisor = std::gcd(std::abs(a), std::abs(b));
        a /= divisor;
        b /= divisor;
        if (a < 0 || (a == 0 && b < 0)) {
            a *= -1;
            b *= -1;
        }
        return { a, b };
    }

    bool Line::operator==(const Line& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    // line: ax + by + c = 0
    // m = -a/b = dy/dx
    // a = -dy, b = dx
    // c = -ax -by
    Line Line::fromPoints(const Point& p1, const Point& p2) {
        const auto [x1, y1] = p1;
        const auto [x2, y2] = p2;
        const auto [a, b] = normalise(y1 - y2, x2 - x1);
        const int c = -a * x1 - b * y1;
        return { a, b, c };
    }

    size_t LineHasher::operator()(const Line& line) const {
        const size_t ha = std::hash<int>()(line.a);
        const size_t hb = std::hash<int>()(line.b);
        const size_t hc = std::hash<int>()(line.c);
        return ha ^ (hb << 2) ^ (hc << 4);
    }
}
