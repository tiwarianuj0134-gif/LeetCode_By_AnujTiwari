#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = lowerBound(nums, target);

        if (left == n || nums[left] != target)
            return {-1, -1};

        int right = upperBound(nums, target) - 1;
        return {left, right};
    }

private:
    int lowerBound(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }

    int upperBound(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] <= target)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};
