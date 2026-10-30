class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        const int n = d.size();

        for (int i = 3; i < n; ++i) {
            const int a = d[i];
            const int b = d[i - 1];
            const int c = d[i - 2];
            const int e = d[i - 3];

            if (a >= c && b <= e)
                return true;

            if (i >= 4 &&
                b == e &&
                a + d[i - 4] >= c)
                return true;

            if (i >= 5 &&
                c >= d[i - 4] &&
                a + d[i - 4] >= c &&
                b <= e &&
                b + d[i - 5] >= e)
                return true;
        }

        return false;
    }
};
