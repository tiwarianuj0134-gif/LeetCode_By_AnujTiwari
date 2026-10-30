class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;

        unordered_set<int> s;
        s.reserve(min(nums.size(), (size_t)k) + 1);

        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i]))
                return true;

            s.insert(nums[i]);

            if (i >= k)
                s.erase(nums[i - k]);
        }

        return false;
    }
};
