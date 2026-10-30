class Solution {
    using ll = long long;

    struct Heap {
        vector<int> h, pos;
        vector<ll>& d;

        Heap(int n, vector<ll>& dist) : pos(n, -1), d(dist) {
            h.reserve(n);
        }

        void update(int x) {
            if (pos[x] == -2) return;

            if (pos[x] == -1) {
                pos[x] = h.size();
                h.push_back(x);
            }

            int i = pos[x];

            while (i > 0) {
                int p = (i - 1) / 4;
                if (d[h[p]] <= d[x]) break;

                h[i] = h[p];
                pos[h[i]] = i;
                i = p;
            }

            h[i] = x;
            pos[x] = i;
        }

        int pop() {
            int res = h[0];
            pos[res] = -2;

            int x = h.back();
            h.pop_back();

            if (!h.empty()) {
                int i = 0, sz = h.size();

                while (true) {
                    int c = 4 * i + 1;
                    if (c >= sz) break;

                    int b = c;
                    for (int j = c + 1; j < min(c + 4, sz); ++j)
                        if (d[h[j]] < d[h[b]]) b = j;

                    if (d[x] <= d[h[b]]) break;

                    h[i] = h[b];
                    pos[h[i]] = i;
                    i = b;
                }

                h[i] = x;
                pos[x] = i;
            }

            return res;
        }

        bool empty() const {
            return h.empty();
        }
    };

public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        if (n == 1) return 0;

        int m = edges.size();

        vector<int> head(n, -1), to(m), wt(m), nxt(m);

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            to[i] = edges[i][1];
            wt[i] = edges[i][2];
            nxt[i] = head[u];
            head[u] = i;
        }

        int N = n * k;
        const ll INF = LLONG_MAX;

        vector<ll> dist(N, INF);
        Heap pq(N, dist);

        dist[0] = 0;
        pq.update(0);

        while (!pq.empty()) {
            int id = pq.pop();
            ll cost = dist[id];

            int u = id / k;
            int run = id % k + 1;

            if (u == n - 1)
                return static_cast<int>(cost);

            for (int e = head[u]; e != -1; e = nxt[e]) {
                int v = to[e];

                int nr = (labels[u] == labels[v]) ? run + 1 : 1;

                if (nr > k) continue;

                int ni = v * k + nr - 1;

                if (pq.pos[ni] == -2) continue;

                ll nd = cost + wt[e];

                if (nd < dist[ni]) {
                    dist[ni] = nd;
                    pq.update(ni);
                }
            }
        }

        return -1;
    }
};
