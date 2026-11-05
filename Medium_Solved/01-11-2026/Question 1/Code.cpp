class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = INT_MAX;

        for (int num : nums) {
            sum += num;
            mn = min(mn, num);
        }

        return static_cast<int>(sum - 1LL * mn * nums.size());
    }
};