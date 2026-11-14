class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {};

        for (int i = 0, n = s.size(); i < n; ++i)
            ++cnt[s[i] - 'a'];

        for (int i = 0, n = s.size(); i < n; ++i)
            if (cnt[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};
