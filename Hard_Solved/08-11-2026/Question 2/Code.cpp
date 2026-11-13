class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> lo, hi;

        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end());
                hi.insert(*it);
                lo.erase(it);
            }

            while (lo.size() < hi.size()) {
                auto it = hi.begin();
                lo.insert(*it);
                hi.erase(it);
            }
        };

        vector<double> ans;
        ans.reserve(nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            long long x = nums[i];

            if (lo.empty() || x <= *lo.rbegin())
                lo.insert(x);
            else
                hi.insert(x);

            balance();

            if (i >= k) {
                long long old = nums[i - k];

                auto it = lo.find(old);

                if (it != lo.end())
                    lo.erase(it);
                else {
                    it = hi.find(old);
                    hi.erase(it);
                }

                balance();
            }

            if (i >= k - 1) {
                if (k & 1) {
                    ans.push_back((double)*lo.rbegin());
                } else {
                    ans.push_back(
                        ((double)*lo.rbegin() + (double)*hi.begin()) / 2.0
                    );
                }
            }
        }

        return ans;
    }
};
