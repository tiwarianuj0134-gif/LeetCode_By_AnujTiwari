class Solution {
    struct TrieNode {
        int next[26];
        bool end;

        TrieNode() : end(false) {
            memset(next, -1, sizeof(next));
        }
    };

    vector<TrieNode> trie;

    void insert(const string& s) {
        int node = 0;

        for (char c : s) {
            int x = c - 'a';

            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[x];
        }

        trie[node].end = true;
    }

    bool isConcatenated(const string& s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;

            int node = 0;

            for (int j = i; j < n; ++j) {
                node = trie[node].next[s[j] - 'a'];

                if (node == -1) break;

                if (trie[node].end) {
                    dp[j + 1] = min(2, dp[j + 1] + dp[i]);

                    if (dp[j + 1] == 2 && j + 1 == n)
                        return true;
                }
            }
        }

        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(
        vector<string>& words
    ) {
        trie.reserve(100001);
        trie.emplace_back();

        for (const string& word : words)
            insert(word);

        vector<string> ans;
        ans.reserve(words.size());

        for (const string& word : words) {
            if (word.size() >= 2 && isConcatenated(word))
                ans.push_back(word);
        }

        return ans;
    }
};
