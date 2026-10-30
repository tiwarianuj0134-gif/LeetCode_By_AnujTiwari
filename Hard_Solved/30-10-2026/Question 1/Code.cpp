class Solution {
    struct Node {
        int head = -1;
        int terminal = -1;
        int palHead = -1;
    };

    struct Edge {
        int to, next;
        unsigned char ch;
    };

    struct Link {
        int id, next;
    };

    vector<Node> tr;
    vector<Edge> edges;
    vector<Link> links;

    int child(int u, int c) {
        for (int e = tr[u].head; e != -1; e = edges[e].next)
            if (edges[e].ch == c)
                return edges[e].to;
        return -1;
    }

    int insertChild(int u, int c) {
        int v = tr.size();
        tr.emplace_back();

        edges.push_back({v, tr[u].head,
                         static_cast<unsigned char>(c)});
        tr[u].head = edges.size() - 1;

        return v;
    }

    void addPal(int u, int id) {
        links.push_back({id, tr[u].palHead});
        tr[u].palHead = links.size() - 1;
    }

    void getPalFlags(const string& s,
                     vector<unsigned char>& pre,
                     vector<unsigned char>& suf) {
        int n = s.size();

        pre.assign(n, 0);
        suf.assign(n, 0);

        vector<int> odd(n), even(n);

        // Manacher: odd-length palindromes.
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 1 :
                min(odd[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n &&
                   s[i - k] == s[i + k])
                ++k;

            odd[i] = k--;

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        // Manacher: even-length palindromes.
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 0 :
                min(even[l + r - i + 1], r - i + 1);

            while (i - k - 1 >= 0 && i + k < n &&
                   s[i - k - 1] == s[i + k])
                ++k;

            even[i] = k--;

            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }

        for (int i = 0; i < n; ++i) {
            // Prefix palindrome.
            if (odd[i] == i + 1)
                pre[2 * i] = 1;

            if (i > 0 && even[i] == i)
                pre[2 * i - 1] = 1;

            // Suffix palindrome.
            if (odd[i] == n - i)
                suf[2 * i - n + 1] = 1;

            if (even[i] == n - i)
                suf[2 * i - n] = 1;
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        int total = 1;

        for (const auto& s : words)
            total += s.size();

        tr.clear();
        edges.clear();
        links.clear();

        tr.reserve(total);
        edges.reserve(total);
        links.reserve(total);

        tr.emplace_back();

        vector<unsigned char> pre, suf;

        // Build reversed trie.
        for (int id = 0; id < n; ++id) {
            const string& s = words[id];
            int len = s.size();

            getPalFlags(s, pre, suf);

            int u = 0;

            for (int j = len - 1; j >= 0; --j) {
                if (pre[j])
                    addPal(u, id);

                int c = s[j] - 'a';
                int v = child(u, c);

                if (v == -1)
                    v = insertChild(u, c);

                u = v;
            }

            tr[u].terminal = id;
            addPal(u, id);
        }

        vector<vector<int>> ans;

        // Search for matching palindrome pairs.
        for (int id = 0; id < n; ++id) {
            const string& s = words[id];
            int len = s.size();

            getPalFlags(s, pre, suf);

            int u = 0;
            bool valid = true;

            for (int j = 0; j < len; ++j) {
                int other = tr[u].terminal;

                if (other != -1 && other != id && suf[j])
                    ans.push_back({id, other});

                u = child(u, s[j] - 'a');

                if (u == -1) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                continue;

            for (int p = tr[u].palHead; p != -1;
                 p = links[p].next) {
                int other = links[p].id;

                if (other != id)
                    ans.push_back({id, other});
            }
        }

        return ans;
    }
};
