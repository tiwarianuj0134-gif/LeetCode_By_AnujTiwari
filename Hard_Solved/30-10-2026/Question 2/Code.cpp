class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        auto it = intervals.lower_bound(value);

        // Already covered by the next interval.
        if (it != intervals.end() && it->first == value)
            return;

        auto prev = intervals.end();

        if (it != intervals.begin()) {
            prev = std::prev(it);

            if (prev->second >= value)
                return;
        }

        bool joinLeft =
            prev != intervals.end() && prev->second + 1 == value;

        bool joinRight =
            it != intervals.end() && it->first - 1 == value;

        if (joinLeft && joinRight) {
            prev->second = it->second;
            intervals.erase(it);
        }
        else if (joinLeft) {
            prev->second = value;
        }
        else if (joinRight) {
            int end = it->second;
            intervals.erase(it);
            intervals.emplace(value, end);
        }
        else {
            intervals.emplace(value, value);
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        ans.reserve(intervals.size());

        for (const auto& [start, end] : intervals)
            ans.push_back({start, end});

        return ans;
    }
};
