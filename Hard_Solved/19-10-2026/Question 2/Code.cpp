class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        string t;
        t.reserve(2 * n + 1);
        t += s;
        t += '#';
        t += rev;

        vector<int> lps(t.size(), 0);

        for (int i = 1, j = 0; i < (int)t.size(); ++i) {
            while (j > 0 && t[i] != t[j])
                j = lps[j - 1];

            if (t[i] == t[j])
                ++j;

            lps[i] = j;
        }

        int prefixLen = lps.back();
        return rev.substr(0, n - prefixLen) + s;
    }
};