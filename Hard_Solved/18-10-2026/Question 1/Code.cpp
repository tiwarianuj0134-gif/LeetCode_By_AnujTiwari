class Solution {
    static constexpr long long MOD = 1'000'000'007LL;
    long long comb[1001][1001]{};

    long long solve(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        left.reserve(n);
        right.reserve(n);

        int root = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = comb[n - 1][left.size()];
        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
