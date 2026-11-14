class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string s = to_string(h) + ":";

                    if (m < 10)
                        s += "0";

                    s += to_string(m);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};