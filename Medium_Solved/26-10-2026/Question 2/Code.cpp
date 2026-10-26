class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        res.reserve(n + 1);

        int i = 0, s = newInterval[0], e = newInterval[1];

        while (i < n && intervals[i][1] < s)
            res.push_back(intervals[i++]);

        while (i < n && intervals[i][0] <= e) {
            s = min(s, intervals[i][0]);
            e = max(e, intervals[i][1]);
            ++i;
        }

        res.push_back({s, e});

        while (i < n)
            res.push_back(intervals[i++]);

        return res;
    }
};
