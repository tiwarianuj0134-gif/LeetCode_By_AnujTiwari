class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];

        bool asc = true, desc = true;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != (s + i) % n)
                asc = false;

            if (nums[i] != (s - i + n) % n)
                desc = false;
        }

        int ans = INT_MAX;

        if (asc) {
            if (s == 0) return 0;
            ans = min(n - s, s + 2);
        }

        if (desc) {
            int k = (s + 1) % n;
            ans = min(ans, 1 + min(k, n - k));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
