class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        long long total = 1;

        while (total < buckets) {
            total *= states;
            ++pigs;
        }

        return pigs;
    }
};
