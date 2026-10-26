class Solution {
    using VI = vector<int>;

    VI maxSubsequence(const VI& nums, int k) {
        VI st;
        st.reserve(k);
        int drop = (int)nums.size() - k;

        for (int x : nums) {
            while (drop > 0 && !st.empty() && st.back() < x) {
                st.pop_back();
                --drop;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    VI mergeMax(const VI& a, const VI& b) {
        int n = a.size(), m = b.size();
        VI res;
        res.reserve(n + m);

        int i = 0, j = 0;

        while (i < n || j < m) {
            if (j == m) {
                res.push_back(a[i++]);
            } else if (i == n) {
                res.push_back(b[j++]);
            } else {
                int x = i, y = j;

                while (x < n && y < m && a[x] == b[y]) {
                    ++x;
                    ++y;
                }

                if (y == m || (x < n && a[x] > b[y]))
                    res.push_back(a[i++]);
                else
                    res.push_back(b[j++]);
            }
        }

        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        VI best;

        for (int x = max(0, k - n); x <= min(k, m); ++x) {
            VI a = maxSubsequence(nums1, x);
            VI b = maxSubsequence(nums2, k - x);
            VI cur = mergeMax(a, b);

            if (cur > best)
                best = move(cur);
        }

        return best;
    }
};
