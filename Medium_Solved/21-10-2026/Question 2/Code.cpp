class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size());
        mp.max_load_factor(0.7f);

        for (const string& s : strs) {
            array<unsigned char, 26> cnt{};
            for (char c : s)
                ++cnt[c - 'a'];

            string key;
            key.assign(reinterpret_cast<const char*>(cnt.data()), cnt.size());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& entry : mp)
            ans.push_back(move(entry.second));

        return ans;
    }
};
