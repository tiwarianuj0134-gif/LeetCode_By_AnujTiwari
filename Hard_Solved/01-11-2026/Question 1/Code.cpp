class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> pos;
    mt19937 rng{random_device{}()};

public:
    RandomizedCollection() {
        nums.reserve(200005);
        pos.reserve(200005);
    }

    bool insert(int val) {
        bool fresh = pos[val].empty();

        pos[val].insert(nums.size());
        nums.push_back(val);

        return fresh;
    }

    bool remove(int val) {
        auto it = pos.find(val);

        if (it == pos.end() || it->second.empty())
            return false;

        int idx = *it->second.begin();
        int lastIdx = nums.size() - 1;
        int lastVal = nums[lastIdx];

        it->second.erase(idx);

        if (idx != lastIdx) {
            pos[lastVal].erase(lastIdx);
            pos[lastVal].insert(idx);
            nums[idx] = lastVal;
        }

        nums.pop_back();

        if (it->second.empty())
            pos.erase(it);

        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};
