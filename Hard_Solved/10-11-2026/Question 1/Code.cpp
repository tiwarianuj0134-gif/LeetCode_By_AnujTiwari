class Solution {
    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;

        int count = mergeSort(nums, temp, left, mid);
        count += mergeSort(nums, temp, mid + 1, right);

        int j = mid + 1;

        for (int i = left; i <= mid; ++i) {
            while (j <= right &&
                   (long long)nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += j - (mid + 1);
        }

        int i = left;
        j = mid + 1;
        int p = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp[p++] = nums[i++];
            else
                temp[p++] = nums[j++];
        }

        while (i <= mid) temp[p++] = nums[i++];
        while (j <= right) temp[p++] = nums[j++];

        for (int x = left; x <= right; ++x)
            nums[x] = temp[x];

        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n - 1);
    }
};