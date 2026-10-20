class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = 0;

            for (int s = 0; s < n; s += k) {
                int e = s + k;
                int mn = nums[s], mx = nums[s];
                int desc = 0;

                for (int i = s; i < e; ++i) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    if (nums[i] > nums[s + (i - s + 1) % k])
                        ++desc;
                }

                if (desc > 1 || (s > 0 && prevMax > mn)) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
