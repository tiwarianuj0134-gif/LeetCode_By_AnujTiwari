class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int start, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        int remaining = k - curr.size();

        for (int i = start; i <= n - remaining + 1; i++) {
            curr.push_back(i);

            backtrack(i + 1, n, k);

            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        curr.clear();

        backtrack(1, n, k);

        return ans;
    }
};
