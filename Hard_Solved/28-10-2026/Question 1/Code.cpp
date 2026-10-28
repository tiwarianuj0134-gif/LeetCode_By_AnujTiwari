class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int i = 0, patches = 0;
        int m = nums.size();

        while (miss <= n) {
            if (i < m && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++patches;
            }
        }

        return patches;
    }
};
