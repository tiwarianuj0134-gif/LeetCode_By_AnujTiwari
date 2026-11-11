class Solution {
public:
    int m, n;
    string w;

    bool dfs(vector<vector<char>>& board, int i, int j, int k) {
        if (k == w.size()) return true;

        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] != w[k])
            return false;

        char c = board[i][j];
        board[i][j] = '#';

        bool found =
            dfs(board, i + 1, j, k + 1) ||
            dfs(board, i - 1, j, k + 1) ||
            dfs(board, i, j + 1, k + 1) ||
            dfs(board, i, j - 1, k + 1);

        board[i][j] = c;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        w = word;

        if (word.size() > m * n) return false;

        int freq[128] = {};

        for (auto& row : board)
            for (char c : row)
                freq[(unsigned char)c]++;

        for (char c : word)
            if (--freq[(unsigned char)c] < 0)
                return false;

        // Search from the rarer endpoint.
        if (freq[(unsigned char)word.back()] <
            freq[(unsigned char)word.front()])
            reverse(w.begin(), w.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == w[0] &&
                    dfs(board, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
