class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m > n) {
            vector<vector<int>> transposed(n, vector<int>(m));

            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    transposed[j][i] = matrix[i][j];

            matrix.swap(transposed);
            swap(m, n);
        }

        int ans = INT_MIN;
        vector<int> sums(n);

        for (int top = 0; top < m; ++top) {
            fill(sums.begin(), sums.end(), 0);

            for (int bottom = top; bottom < m; ++bottom) {
                for (int j = 0; j < n; ++j)
                    sums[j] += matrix[bottom][j];

                set<int> prefix;
                prefix.insert(0);

                int curr = 0;

                for (int x : sums) {
                    curr += x;

                    auto it = prefix.lower_bound(curr - k);

                    if (it != prefix.end()) {
                        ans = max(ans, curr - *it);

                        if (ans == k)
                            return k;
                    }

                    prefix.insert(curr);
                }
            }
        }

        return ans;
    }
};