class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int n = stones.size();

        if (stones[1] != 1) return false;

        vector<vector<unsigned char>> dp(
            n, vector<unsigned char>(n + 1, 0)
        );

        unordered_map<int, int> pos;
        pos.reserve(n * 2);
        pos.max_load_factor(0.7f);

        for (int i = 0; i < n; ++i) {
            if (i > 0 && stones[i] - stones[i - 1] > i)
                return false;

            pos.emplace(stones[i], i);
        }

        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= i; ++k) {
                if (!dp[i][k]) continue;

                int low = max(1, k - 1);
                int high = k + 1;

                for (int jump = low; jump <= high; ++jump) {
                    long long target = 1LL * stones[i] + jump;

                    if (target > stones.back()) continue;

                    auto it = pos.find((int)target);

                    if (it == pos.end()) continue;

                    int j = it->second;

                    if (j == n - 1) return true;

                    dp[j][jump] = 1;
                }
            }
        }

        return false;
    }
};