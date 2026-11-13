
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>> dp(n);

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            dp[i].reserve(i);

            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];

                int cnt = 0;

                auto it = dp[j].find(diff);

                if (it != dp[j].end())
                    cnt = it->second;

                ans += cnt;
                dp[i][diff] += cnt + 1;
            }
        }

        return (int)ans;
    }
};
