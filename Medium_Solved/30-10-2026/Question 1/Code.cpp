class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] || grid[m - 1][n - 1])
            return 0;

        int dp[101] = {};
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            int left = 0;
            const auto& row = grid[i];

            for (int j = 0; j < n; ++j) {
                if (row[j])
                    dp[j] = 0;
                else
                    dp[j] += left;

                left = dp[j];
            }
        }

        return dp[n - 1];
    }
};
