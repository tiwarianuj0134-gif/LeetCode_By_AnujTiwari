class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n < m) {
            swap(word1, word2);
            swap(n, m);
        }

        vector<int> dp(m + 1);

        for (int j = 0; j <= m; ++j)
            dp[j] = j;

        for (int i = 1; i <= n; ++i) {
            int diagonal = dp[0];
            dp[0] = i;

            for (int j = 1; j <= m; ++j) {
                int top = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = diagonal;
                } else {
                    dp[j] = 1 + min({
                        diagonal,  // Replace
                        dp[j],      // Delete
                        dp[j - 1]   // Insert
                    });
                }

                diagonal = top;
            }
        }

        return dp[m];
    }
};
