class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (int m = 60; m >= 2; --m) {
            long long low = 2;
            long long high = (long long)pow(
                (long double)num, 1.0L / (m - 1)
            ) + 2;

            while (low <= high) {
                long long base = low + (high - low) / 2;
                __int128 sum = 1;
                
                for (int i = 0; i < m - 1; ++i) {
                    sum = sum * base + 1;

                    if (sum > num) break;
                }

                if (sum == num)
                    return to_string(base);

                if (sum < num)
                    low = base + 1;
                else
                    high = base - 1;
            }
        }

        return to_string(num - 1);
    }
};
