class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> deg(m * n, 0);
        queue<int> q;

        constexpr int dr[] = {-1, 1, 0, 0};
        constexpr int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int id = r * n + c;
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        matrix[nr][nc] < matrix[r][c]) {
                        ++deg[id];
                    }
                }
                if (deg[id] == 0)
                    q.push(id);
            }
        }

        int length = 0;

        while (!q.empty()) {
            int sz = q.size();
            ++length;

            while (sz--) {
                int id = q.front();
                q.pop();

                int r = id / n, c = id % n;

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        matrix[nr][nc] <= matrix[r][c])
                        continue;

                    int next = nr * n + nc;
                    if (--deg[next] == 0)
                        q.push(next);
                }
            }
        }

        return length;
    }
};