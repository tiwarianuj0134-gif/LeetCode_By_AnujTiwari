class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> st;
        vector<int> nxt(n, n);
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + nums[i];

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty()) nxt[i] = st.back();
            st.push_back(i);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> cost(
            LOG, vector<long long>(n + 1, 0)
        );

        for (int i = 0; i < n; ++i) {
            up[0][i] = nxt[i];
            cost[0][i] = 1LL * nums[i] * (nxt[i] - i)
                       - (pref[nxt[i]] - pref[i]);
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                cost[j][i] = cost[j - 1][i]
                           + cost[j - 1][mid];
            }
        }

        auto getCost = [&](int l, int r) -> long long {
            long long res = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][cur] <= r) {
                    res += cost[j][cur];
                    cur = up[j][cur];
                }
            }

            return res + 1LL * nums[cur] * (r - cur + 1)
                       - (pref[r + 1] - pref[cur]);
        };

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (l <= r && getCost(l, r) > k)
                ++l;

            ans += r - l + 1;
        }

        return ans;
    }
};
