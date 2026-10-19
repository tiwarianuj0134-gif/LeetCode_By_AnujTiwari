class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        string res(n + m, '0');

        for (int i = n - 1; i >= 0; --i) {
            int carry = 0;
            int a = num1[i] - '0';

            for (int j = m - 1; j >= 0; --j) {
                int sum = (res[i + j + 1] - '0')
                        + a * (num2[j] - '0')
                        + carry;

                res[i + j + 1] = char('0' + sum % 10);
                carry = sum / 10;
            }

            res[i] = char(res[i] + carry);
        }

        size_t first = res.find_first_not_of('0');
        return first == string::npos ? "0" : res.substr(first);
    }
};
