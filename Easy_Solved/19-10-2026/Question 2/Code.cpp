class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        ans.reserve(7);

        while (columnNumber > 0) {
            --columnNumber;
            ans.push_back('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};