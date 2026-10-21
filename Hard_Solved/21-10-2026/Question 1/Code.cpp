class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0 || indexDiff <= 0) return false;

        const long long w = (long long)valueDiff + 1;
        unordered_map<long long, long long> buckets;
        buckets.reserve(min(nums.size(), (size_t)indexDiff + 1));
        buckets.max_load_factor(0.7f);

        auto getBucket = [&](long long x) -> long long {
            return x < 0 ? (x + 1) / w - 1 : x / w;
        };

        for (int i = 0; i < (int)nums.size(); ++i) {
            long long x = nums[i];
            long long id = getBucket(x);

            if (buckets.count(id)) return true;

            auto left = buckets.find(id - 1);
            if (left != buckets.end() && x - left->second < w)
                return true;

            auto right = buckets.find(id + 1);
            if (right != buckets.end() && right->second - x < w)
                return true;

            buckets[id] = x;

            if (i >= indexDiff) {
                long long oldId = getBucket(nums[i - indexDiff]);
                buckets.erase(oldId);
            }
        }

        return false;
    }
};
