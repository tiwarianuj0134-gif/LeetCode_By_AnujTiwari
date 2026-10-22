class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;

        for (long long factor = 1; factor <= n; factor *= 10) {
            long long lower = n % factor;
            long long current = (n / factor) % 10;
            long long higher = n / (factor * 10);

            count += higher * factor;

            if (current == 1) {
                count += lower + 1;
            } else if (current > 1) {
                count += factor;
            }
        }

        return static_cast<int>(count);
    }
};