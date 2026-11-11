class Solution {
public:
    vector<string> ans;
    string path;

    void backtrack(const string& s, int start, int parts) {
        int remaining = s.size() - start;

        // Prune impossible segment lengths.
        if (remaining < parts || remaining > parts * 3)
            return;

        if (parts == 0) {
            if (start == s.size())
                ans.push_back(path.substr(0, path.size() - 1));
            return;
        }

        int value = 0;
        int oldSize = path.size();

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            if (len > 1 && s[start] == '0')
                break;

            value = value * 10 + (s[start + len - 1] - '0');

            if (value > 255)
                break;

            path.append(s, start, len);
            path.push_back('.');

            backtrack(s, start + len, parts - 1);

            path.resize(oldSize);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        path.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        backtrack(s, 0, 4);

        return ans;
    }
};
