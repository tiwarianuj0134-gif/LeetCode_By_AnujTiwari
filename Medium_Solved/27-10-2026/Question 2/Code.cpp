class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));

        int r = 0, c = 0, d = 0;
        const int dr[] = {0, 1, 0, -1};
        const int dc[] = {1, 0, -1, 0};

        for (int v = 1; v <= n * n; ++v) {
            a[r][c] = v;

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || a[nr][nc]) {
                d = (d + 1) & 3;
                nr = r + dr[d];
                nc = c + dc[d];
            }

            r = nr;
            c = nc;
        }

        return a;
    }
};