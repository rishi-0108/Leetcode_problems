
class Solution {
    static constexpr long long MOD = 1'000'000'007;
    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;
        long long oldSum = seg[node].sum;

        seg[node].sq = (seg[node].sq
            + 2 * x % MOD * oldSum % MOD
            + len % MOD * x % MOD * x % MOD) % MOD;

        seg[node].sum = (oldSum + len * x) % MOD;
        seg[node].lazy = (seg[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        long long x = seg[node].lazy;

        apply(node * 2, l, mid, x);
        apply(node * 2 + 1, mid + 1, r, x);

        seg[node].lazy = 0;
    }

    void pull(int node) {
        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;
        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = l + (r - l) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);
        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node{});

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int p = last[nums[r]];
            update(1, 0, n - 1, p + 1, r);

            ans = (ans + seg[1].sq) % MOD;
            last[nums[r]] = r;
        }

        return ans;
    }
};
