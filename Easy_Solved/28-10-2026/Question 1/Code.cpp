class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastS[256] = {}, lastT[256] = {};

        for (int i = 0; i < s.size(); ++i) {
            unsigned char a = s[i], b = t[i];

            if (lastS[a] != lastT[b])
                return false;

            lastS[a] = lastT[b] = i + 1;
        }

        return true;
    }
};
