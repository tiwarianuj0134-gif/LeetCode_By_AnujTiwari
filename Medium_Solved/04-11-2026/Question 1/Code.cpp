class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(vector<int>& nums, int start) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);

            backtrack(nums, i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        curr.clear();

        backtrack(nums, 0);

        return ans;
    }
};