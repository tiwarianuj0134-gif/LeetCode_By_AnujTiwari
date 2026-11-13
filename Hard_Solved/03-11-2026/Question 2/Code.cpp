class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;

        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;
            int parts = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    ++parts;
                    sum = x;

                    if (parts > k) break;
                } else {
                    sum += x;
                }
            }

            if (parts <= k)
                high = mid;
            else
                low = mid + 1;
        }

        return (int)low;
    }
};
