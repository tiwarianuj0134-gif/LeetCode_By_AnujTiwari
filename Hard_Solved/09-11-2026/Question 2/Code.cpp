#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> memo;
    static constexpr int INF = 1e9;
    const string COL = "RYBGW";

    // Remove all groups of 3+ including chain reactions.
    static string clean(const string& s) {
        string cur = s;
        while (true) {
            string t;
            bool removed = false;
            int n = cur.size();
            for (int i = 0; i < n;) {
                int j = i + 1;
                while (j < n && cur[j] == cur[i]) ++j;
                if (j - i >= 3) removed = true;
                else t.append(cur, i, j - i);
                i = j;
            }
            if (!removed) return cur;
            cur.swap(t);
        }
    }

    int dfs(const string& board, array<int, 5>& cnt) {
        if (board.empty()) return 0;

        string key = board;
        key.push_back('#');
        for (int k = 0; k < 5; ++k) key.push_back('0' + cnt[k]);

        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int res = INF;
        int n = board.size();

        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k < 5; ++k) {
                if (cnt[k] == 0) continue;
                char c = COL[k];

                // same run: equivalent to inserting at its start
                if (i > 0 && board[i - 1] == c) continue;

                bool sameNext = (i < n && board[i] == c);
                bool splitPair = (i > 0 && i < n &&
                                  board[i - 1] == board[i] && board[i] != c);
                if (!sameNext && !splitPair) continue;

                string nb = board;
                nb.insert(nb.begin() + i, c);
                nb = clean(nb);

                --cnt[k];
                int sub = dfs(nb, cnt);
                ++cnt[k];

                if (sub != INF) res = min(res, 1 + sub);
            }
        }

        return memo[key] = res;
    }

public:
    int findMinStep(string board, string hand) {
        memo.clear();
        array<int, 5> cnt{};
        for (char ch : hand) cnt[COL.find(ch)]++;
        int ans = dfs(board, cnt);
        return ans >= INF ? -1 : ans;
    }
};
