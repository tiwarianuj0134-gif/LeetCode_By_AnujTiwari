class Solution {
    static constexpr int LOG = 17;

    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit, mask;
    int timer = 0;

    void add(int idx, int val) {
        for (int n = (int)bit.size(); idx < n; idx += idx & -idx)
            bit[idx] ^= val;
    }

    int prefixQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];
        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; --j) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 2, 0);
        mask.resize(n);

        for (int i = 0; i < n; ++i)
            mask[i] = 1 << (s[i] - 'a');

        // Iterative DFS with entry/exit events.
        vector<pair<int, int>> st;
        st.reserve(2 * n);
        st.push_back({0, -1});

        vector<int> parent(n, -1);
        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            if (state == -1) {
                tin[u] = ++timer;
                up[0][u] = (parent[u] == -1 ? 0 : parent[u]);

                for (int j = 1; j < LOG; ++j)
                    up[j][u] = up[j - 1][up[j - 1][u]];

                st.push_back({u, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
                    int v = adj[u][i];
                    if (v == parent[u]) continue;

                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, -1});
                }
            } else {
                tout[u] = timer;
            }
        }

        // Euler subtree range-XOR updates.
        for (int u = 0; u < n; ++u) {
            add(tin[u], mask[u]);
            add(tout[u] + 1, mask[u]);
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            int p1 = q.find(' ');
            int p2 = q.find(' ', p1 + 1);

            if (q[0] == 'u') {
                int u = stoi(q.substr(p1 + 1, p2 - p1 - 1));
                char c = q[p2 + 1];

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                if (delta != 0) {
                    add(tin[u], delta);
                    add(tout[u] + 1, delta);
                    mask[u] = newMask;
                }
            } else {
                int u = stoi(q.substr(p1 + 1, p2 - p1 - 1));
                int v = stoi(q.substr(p2 + 1));

                int w = lca(u, v);

                int pathMask = prefixQuery(tin[u])
                             ^ prefixQuery(tin[v])
                             ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};