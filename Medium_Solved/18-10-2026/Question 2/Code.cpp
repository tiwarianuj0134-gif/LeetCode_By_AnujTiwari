class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(const vector<int>& a, int start, int rem) {
        if (rem == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < (int)a.size(); ++i) {
            if (a[i] > rem) break;
            if (i > start && a[i] == a[i - 1]) continue;

            path.push_back(a[i]);
            dfs(a, i + 1, rem - a[i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        ans.clear();
        path.clear();
        path.reserve(min((int)candidates.size(), target));

        dfs(candidates, 0, target);
        return ans;
    }
};
