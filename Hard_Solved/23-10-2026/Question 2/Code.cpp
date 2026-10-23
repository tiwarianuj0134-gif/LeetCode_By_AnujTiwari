class Solution {
    const string below20[20] = {
        "", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };

    const string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int n) {
        if (n == 0) return "";
        if (n < 20) return below20[n] + " ";
        if (n < 100)
            return tens[n / 10] + " " + helper(n % 10);
        return below20[n / 100] + " Hundred " + helper(n % 100);
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        const string units[] = {
            "", "Thousand", "Million", "Billion"
        };

        string result;
        int group = 0;

        while (num > 0) {
            int chunk = num % 1000;

            if (chunk > 0) {
                string part = helper(chunk);
                if (!units[group].empty())
                    part += units[group] + " ";
                result = part + result;
            }

            num /= 1000;
            ++group;
        }

        if (!result.empty())
            result.pop_back();

        return result;
    }
};