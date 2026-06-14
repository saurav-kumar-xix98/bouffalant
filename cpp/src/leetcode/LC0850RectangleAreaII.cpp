#include "leetcode/LC0850RectangleAreaII.hpp"

#include <algorithm>
#include <list>

namespace {
    constexpr long long MOD = 1'000'000'007;
    struct Interval {
        int start, end;
    };
    struct Event {
        int x;
        Interval interval;
        bool isStart;
    };

    void insertInterval(std::list<Interval> &intervals, const Interval& interval);
    void eraseInterval(std::list<Interval> &intervals, const Interval& interval);
    long long coveredHeight(const std::list<Interval> &intervals);
}

int LC0850RectangleAreaII::rectangleArea(const std::vector<std::vector<int>>& rectangles) {
    std::vector<Event> events;
    events.reserve(2 * rectangles.size());

    for (const auto & rect : rectangles) {
        events.push_back({ rect[0], {rect[1], rect[3]}, true });
        events.push_back({ rect[2], {rect[1], rect[3]}, false });
    }

    std::ranges::sort(events, {}, &Event::x);

    std::list<Interval> activeIntervals;

    long long ans = 0;
    long long previousX = events[0].x;

    insertInterval(activeIntervals, events[0].interval);

    for (size_t i = 1; i < events.size(); ++i) {
        const auto& [x, interval, isStart] = events[i];

        ans = (ans + (static_cast<long long>(x) - previousX) * coveredHeight(activeIntervals)) % MOD;
        previousX = x;

        if (isStart) {
            insertInterval(activeIntervals, interval);
        } else {
            eraseInterval(activeIntervals, interval);
        }
    }

    return static_cast<int>(ans);
}

namespace {
    void insertInterval(std::list<Interval> &intervals, const Interval& interval) {
        auto itr = intervals.begin();

        while (itr != intervals.end() && itr->start < interval.start) {
            ++itr;
        }

        intervals.insert(itr, interval);
    }

    void eraseInterval(std::list<Interval> &intervals, const Interval& interval) {
        for (auto itr = intervals.begin(); itr != intervals.end(); ++itr) {
            if (itr->start == interval.start && itr->end == interval.end) {
                intervals.erase(itr);
                return;
            }
        }
    }

    bool overlaps(const Interval &lhs, const Interval &rhs) {
        return !(lhs.end < rhs.start || lhs.start > rhs.end);
    }

    Interval merge(const Interval &lhs, const Interval &rhs) {
        return {std::min(lhs.start, rhs.start), std::ranges::max(lhs.end, rhs.end)};
    }

    long long coveredHeight(const std::list<Interval> &intervals) {
        if (intervals.empty()) {
            return 0;
        }

        long long ans = 0;
        auto itr = intervals.begin();
        auto curr = *itr++;

        while (itr != intervals.end()) {
            if (overlaps(curr, *itr)) {
                curr = merge(curr, *itr);
            } else {
                auto span = (curr.end - curr.start) % MOD;
                ans = (ans + span) % MOD;
                curr = *itr;
            }
            ++itr;
        }
        const auto span = (curr.end - curr.start) % MOD;
        ans = (ans + span) % MOD;
        return ans;
    }
}
