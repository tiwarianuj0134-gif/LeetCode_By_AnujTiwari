class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        unordered_set<unsigned long long> corners;
        corners.reserve(rectangles.size() * 4);
        corners.max_load_factor(0.7f);

        auto encode = [](int x, int y) -> unsigned long long {
            return (static_cast<unsigned long long>(
                        static_cast<unsigned int>(x + 100000)
                    ) << 32) |
                   static_cast<unsigned int>(y + 100000);
        };

        auto toggle = [&](int x, int y) {
            unsigned long long key = encode(x, y);

            auto it = corners.find(key);

            if (it == corners.end())
                corners.insert(key);
            else
                corners.erase(it);
        };

        for (const auto& r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            area += 1LL * (x2 - x1) * (y2 - y1);

            toggle(x1, y1);
            toggle(x1, y2);
            toggle(x2, y1);
            toggle(x2, y2);
        }

        long long boundingArea =
            1LL * (maxX - minX) * (maxY - minY);

        if (area != boundingArea)
            return false;

        if (corners.size() != 4)
            return false;

        return corners.count(encode(minX, minY)) &&
               corners.count(encode(minX, maxY)) &&
               corners.count(encode(maxX, minY)) &&
               corners.count(encode(maxX, maxY));
    }
};