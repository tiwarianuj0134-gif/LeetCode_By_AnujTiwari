class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int mp[26] = {};
        unordered_map<string_view, int> ids;
        
        int id = 0;
        int i = 0, j = 0;
        int n = pattern.size(), m = s.size();

        while (i < n && j < m) {
            int start = j;

            while (j < m && s[j] != ' ') ++j;

            string_view word(s.data() + start, j - start);
            int c = pattern[i] - 'a';

            auto it = ids.find(word);

            if (mp[c] == 0) {
                if (it != ids.end()) return false;

                mp[c] = ++id;
                ids.emplace(word, id);
            } 
            else {
                if (it == ids.end() || it->second != mp[c])
                    return false;
            }

            ++i;
            ++j;
        }

        return i == n && j == m + 1;
    }
};
