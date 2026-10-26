class Solution {
    void update(vector<int>& bit, int i, int n) {
        for (; i <= n; i += i & -i)
            ++bit[i];
    }

    int query(const vector<int>& bit, int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();
        vector<int> bit(m + 1, 0);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            int rank = lower_bound(sorted.begin(), sorted.end(), nums[i])
                       - sorted.begin() + 1;

            ans[i] = query(bit, rank - 1);
            update(bit, rank, m);
        }

        return ans;
    }
};