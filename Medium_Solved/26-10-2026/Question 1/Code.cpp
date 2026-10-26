class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<int> q;
        q.reserve(m * n);

        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] <= 0) continue;

                q.clear();
                q.push_back(i * n + j);

                long long sum = grid[i][j];
                grid[i][j] = 0;

                for (size_t head = 0; head < q.size(); ++head) {
                    const int pos = q[head];
                    const int r = pos / n;
                    const int c = pos % n;

                    if (r > 0 && grid[r - 1][c] > 0) {
                        sum += grid[r - 1][c];
                        grid[r - 1][c] = 0;
                        q.push_back(pos - n);
                    }

                    if (r + 1 < m && grid[r + 1][c] > 0) {
                        sum += grid[r + 1][c];
                        grid[r + 1][c] = 0;
                        q.push_back(pos + n);
                    }

                    if (c > 0 && grid[r][c - 1] > 0) {
                        sum += grid[r][c - 1];
                        grid[r][c - 1] = 0;
                        q.push_back(pos - 1);
                    }

                    if (c + 1 < n && grid[r][c + 1] > 0) {
                        sum += grid[r][c + 1];
                        grid[r][c + 1] = 0;
                        q.push_back(pos + 1);
                    }
                }

                if (sum % k == 0) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
