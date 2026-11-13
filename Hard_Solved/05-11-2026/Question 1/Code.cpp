class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        --k;

        auto count = [&](long long prefix) -> long long {
            long long first = prefix;
            long long last = prefix;
            long long total = 0;

            while (first <= n) {
                total += min((long long)n + 1, last + 1) - first;
                first *= 10;
                last = last * 10 + 9;
            }

            return total;
        };

        while (k > 0) {
            long long steps = count(curr);

            if (steps <= k) {
                ++curr;
                k -= steps;
            } else {
                curr *= 10;
                --k;
            }
        }

        return (int)curr;
    }
};
