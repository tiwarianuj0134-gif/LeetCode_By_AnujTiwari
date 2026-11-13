class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            vis[i][0] = vis[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[m - 1][j], m - 1, j);
            vis[0][j] = vis[m - 1][j] = true;
        }

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        int ans = 0;

        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n || vis[nr][nc])
                    continue;

                vis[nr][nc] = true;

                int nh = heightMap[nr][nc];

                if (nh < h)
                    ans += h - nh;

                pq.emplace(max(h, nh), nr, nc);
            }
        }

        return ans;
    }
};