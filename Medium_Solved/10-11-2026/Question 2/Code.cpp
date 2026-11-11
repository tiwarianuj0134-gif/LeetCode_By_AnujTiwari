class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size())
            return false;

        // Keep s2 as the shorter string.
        if (n > m) {
            swap(s1, s2);
            swap(m, n);
        }

        vector<char> dp(n + 1, false);

        dp[0] = true;

        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= n; j++) {
                char c = s3[i + j - 1];

                dp[j] = (dp[j] && s1[i - 1] == c) ||
                        (dp[j - 1] && s2[j - 1] == c);
            }
        }

        return dp[n];
    }
};
