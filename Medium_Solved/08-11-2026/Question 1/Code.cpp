class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (s[0] == '0') return 0;

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 1; i < n; i++) {
            int curr = 0;

            // Decode one digit.
            if (s[i] != '0')
                curr += prev1;

            // Decode two digits.
            int two = (s[i - 1] - '0') * 10 +
                      (s[i] - '0');

            if (two >= 10 && two <= 26)
                curr += prev2;

            prev2 = prev1;
            prev1 = curr;

            if (prev1 == 0)
                return 0;
        }

        return prev1;
    }
};
