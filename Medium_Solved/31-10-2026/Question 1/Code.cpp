class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();

        vector<int> right(n, 0), down(n, 0);
        right[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r = right[j];
                int d = down[j];

                if (i == m - 1 && j == n - 1)
                    return (r + d) % MOD;

                right[j] = 0;
                down[j] = 0;

                if (grid[i][j] == 0) {
                    // Empty cell: both directions continue.
                    if (j + 1 < n)
                        right[j + 1] =
                            (right[j + 1] + r + d) % MOD;

                    if (i + 1 < m)
                        down[j] = (r + d) % MOD;
                } else {
                    // Mirror: right -> down, down -> right.
                    if (i + 1 < m)
                        down[j] = r;

                    if (j + 1 < n)
                        right[j + 1] =
                            (right[j + 1] + d) % MOD;
                }
            }
        }

        return 0;
    }
};
