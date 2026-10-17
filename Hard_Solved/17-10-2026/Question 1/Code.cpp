class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 2;

        for (int i = 0; i < n - 1; ++i) {
            unordered_map<long long, int> cnt;
            cnt.reserve(n * 2);

            int best = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                long long key =
                    (static_cast<long long>(dx + 20000) << 32) |
                    static_cast<unsigned int>(dy + 20000);

                best = max(best, ++cnt[key]);
            }

            ans = max(ans, best + 1);
            if (ans >= n - i) break;
        }

        return ans;
    }
};