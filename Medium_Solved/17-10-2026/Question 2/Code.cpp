class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        while (--n) {
            string t;
            t.reserve(s.size() * 2);

            for (int i = 0, j, len = s.size(); i < len; i = j) {
                j = i + 1;

                while (j < len && s[j] == s[i])
                    ++j;

                t += to_string(j - i);
                t += s[i];
            }

            s.swap(t);
        }

        return s;
    }
};
