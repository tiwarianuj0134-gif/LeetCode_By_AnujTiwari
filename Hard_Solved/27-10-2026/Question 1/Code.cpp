class Solution {
    using ll = long long;

    vector<ll> sums, temp;
    ll lower, upper;

    int mergeCount(int left, int right) {
        if (right - left <= 1) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeCount(left, mid) + mergeCount(mid, right);

        int lo = mid, hi = mid;
        for (int i = left; i < mid; ++i) {
            while (lo < right && sums[lo] - sums[i] < lower)
                ++lo;
            while (hi < right && sums[hi] - sums[i] <= upper)
                ++hi;
            count += hi - lo;
        }

        int i = left, j = mid, k = left;
        while (i < mid && j < right) {
            if (sums[i] <= sums[j])
                temp[k++] = sums[i++];
            else
                temp[k++] = sums[j++];
        }

        while (i < mid) temp[k++] = sums[i++];
        while (j < right) temp[k++] = sums[j++];

        for (int p = left; p < right; ++p)
            sums[p] = temp[p];

        return count;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;

        int n = nums.size();
        sums.resize(n + 1);
        temp.resize(n + 1);

        sums[0] = 0;
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];

        return mergeCount(0, n + 1);
    }
};