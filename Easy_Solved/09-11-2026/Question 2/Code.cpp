class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool seen[1001] = {};

        for (int x : nums1) {
            seen[x] = true;
        }

        vector<int> ans;
        for (int x : nums2) {
            if (seen[x]) {
                ans.push_back(x);
                seen[x] = false;
            }
        }

        return ans;
    }
};
