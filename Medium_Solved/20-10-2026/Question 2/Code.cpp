class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        auto dfs = [&](auto&& self, int idx) -> void {
            if (idx == n) {
                ans.push_back(nums);
                return;
            }

            for (int i = idx; i < n; ++i) {
                swap(nums[idx], nums[i]);
                self(self, idx + 1);
                swap(nums[idx], nums[i]);
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};
