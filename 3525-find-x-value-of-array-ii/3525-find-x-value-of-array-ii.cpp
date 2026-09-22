class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> seg;

    Node merge(Node left, Node right) {
        Node res;

        // Product of the whole segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside the left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes which contain the whole left segment
        // and some prefix of the right segment
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node node;

        val %= k;

        node.prod = val;
        node.cnt[val] = 1;   // the element itself is a prefix

        return node;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = makeNode(val);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        // Completely inside query range
        if (ql <= l && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        // Query lies completely in right
        if (ql > mid) {
            return query(idx * 2 + 1, mid + 1, r, ql, qr);
        }

        // Query lies completely in left
        if (qr <= mid) {
            return query(idx * 2, l, mid, ql, qr);
        }

        // Query overlaps both
        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->nums = nums;
        this->k = k;
        this->n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // We need all non-empty prefixes of nums[start...n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};