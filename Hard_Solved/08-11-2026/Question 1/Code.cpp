class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);

        for (long long left = upper; left >= lower; --left) {
            long long pal = left;
            long long x = left;

            while (x > 0) {
                pal = pal * 10 + x % 10;
                x /= 10;
            }

            for (long long i = upper; i * i >= pal; --i) {
                if (pal % i == 0 && pal / i <= upper) {
                    return pal % 1337;
                }
            }
        }

        return 0;
    }
};
