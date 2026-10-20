class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<array<int, 3>> events;
        events.reserve(buildings.size() * 2);

        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], 0, 0});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        int prev = 0;
        int i = 0, m = events.size();

        while (i < m) {
            int x = events[i][0];

            while (i < m && events[i][0] == x) {
                if (events[i][1] < 0)
                    pq.push({-events[i][1], events[i][2]});
                ++i;
            }

            while (!pq.empty() && pq.top().second <= x)
                pq.pop();

            int curr = pq.empty() ? 0 : pq.top().first;

            if (curr != prev) {
                ans.push_back({x, curr});
                prev = curr;
            }
        }

        return ans;
    }
};
