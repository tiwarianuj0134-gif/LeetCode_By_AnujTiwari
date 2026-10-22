class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n - k + 1);

        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            // Remove indices outside the current window.
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove elements smaller than the current element.
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // The first complete window starts at i = k - 1.
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
