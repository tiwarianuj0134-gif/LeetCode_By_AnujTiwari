class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int p = (num1[i] - '0') * (num2[j] - '0');
                int sum = p + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans;
        ans.reserve(n + m);

        int i = 0;
        while (i < n + m && res[i] == 0) ++i;

        for (; i < n + m; ++i)
            ans.push_back(char('0' + res[i]));

        return ans;
    }
};
