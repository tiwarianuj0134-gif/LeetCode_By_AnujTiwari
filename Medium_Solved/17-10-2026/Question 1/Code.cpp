class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; ++i) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            a[i] = {sum, nums[i]};
        }

        sort(a.begin(), a.end());

        vector<int> p(n);
        vector<int> sortedPos(n);
        for (int i = 0; i < n; ++i)
            original[i] = {nums[i], i};

        sort(original.begin(), original.end());

        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(original.begin(), original.end(),
                                  make_pair(a[i].second, 0)) - original.begin();
            sortedPos[original[idx].second] = i;
        }

        for (int i = 0; i < n; ++i)
            p[i] = sortedPos[i];

        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            while (p[i] != i) {
                int j = p[i];
                swap(p[i], p[j]);
                ++swaps;
            }
        }

        return swaps;
    }
};