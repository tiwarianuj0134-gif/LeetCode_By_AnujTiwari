class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        function<void(int, int)> dfs = [&](int start, int remaining) {
            if (remaining == 0) {
                ans.push_back(path);
                return;
            }

            for (int i = start; i < (int)candidates.size(); ++i) {
                int x = candidates[i];

                if (x > remaining) break;

                path.push_back(x);
                dfs(i, remaining - x);  // Reuse the same candidate.
                path.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};
