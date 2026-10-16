#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1LL;

        tree[p].sq = (tree[p].sq
            + 2LL * v % MOD * tree[p].sum % MOD
            + v * v % MOD * len % MOD) % MOD;

        tree[p].sum = (tree[p].sum + v * len) % MOD;
        tree[p].lazy = (tree[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (tree[p].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long v = tree[p].lazy;

        apply(p * 2, l, mid, v);
        apply(p * 2 + 1, mid + 1, r, v);

        tree[p].lazy = 0;
    }

    void pull(int p) {
        tree[p].sum =
            (tree[p * 2].sum + tree[p * 2 + 1].sum) % MOD;

        tree[p].sq =
            (tree[p * 2].sq + tree[p * 2 + 1].sq) % MOD;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int mid = l + (r - l) / 2;

        if (ql <= mid)
            update(p * 2, l, mid, ql, qr);

        if (qr > mid)
            update(p * 2 + 1, mid + 1, r, ql, qr);

        pull(p);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = static_cast<int>(nums.size());
        tree.assign(4 * n + 5, Node{});

        // Values can be up to 100000, independently of n.
        vector<int> last(100001, -1);

        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int x = nums[r];
            int left = last[x] + 1;

            update(1, 0, n - 1, left, r);

            ans += tree[1].sq;
            if (ans >= MOD)
                ans -= MOD;

            last[x] = r;
        }

        return static_cast<int>(ans);
    }
};