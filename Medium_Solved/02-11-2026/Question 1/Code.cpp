class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long both = min(need1, need2);
        long long remaining1 = need1 - both;
        long long remaining2 = need2 - both;

        long long ans = both * min((long long)costBoth,
                                   (long long)cost1 + cost2);

        ans += remaining1 * min((long long)cost1,
                                (long long)costBoth);

        ans += remaining2 * min((long long)cost2,
                                (long long)costBoth);

        return ans;
    }
};
