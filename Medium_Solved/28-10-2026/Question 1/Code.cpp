class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int K = 1024;

        vector<bitset<K>> dp(n);

        dp[0].set(grid[0][0]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                bitset<K> cur;

                if (i > 0) {
                    for (int x = 0; x < K; ++x)
                        if (dp[j][x])
                            cur.set(x ^ grid[i][j]);
                }

                if (j > 0) {
                    for (int x = 0; x < K; ++x)
                        if (dp[j - 1][x])
                            cur.set(x ^ grid[i][j]);
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < K; ++x)
            if (dp[n - 1][x])
                return x;

        return 0;
    }
};
