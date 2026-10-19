class Solution {
    struct Node {
        Node* next[26]{};
        string word;
    };

    Node* root;
    vector<string> ans;
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        char ch = board[r][c];
        if (ch == '#') return;

        Node* cur = node->next[ch - 'a'];
        if (!cur) return;

        if (!cur->word.empty()) {
            ans.push_back(cur->word);
            cur->word.clear();
        }

        board[r][c] = '#';

        if (r > 0)     dfs(board, r - 1, c, cur);
        if (r + 1 < m) dfs(board, r + 1, c, cur);
        if (c > 0)     dfs(board, r, c - 1, cur);
        if (c + 1 < n) dfs(board, r, c + 1, cur);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        Node trie[1]; // Not used for dynamic storage
        root = new Node();

        for (const string& w : words) {
            Node* p = root;
            for (char ch : w) {
                int idx = ch - 'a';
                if (!p->next[idx])
                    p->next[idx] = new Node();
                p = p->next[idx];
            }
            p->word = w;
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root);

        return ans;
    }
};