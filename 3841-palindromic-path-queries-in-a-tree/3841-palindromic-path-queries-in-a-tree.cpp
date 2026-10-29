class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 17;
        while ((1 << LOG) <= n) LOG++;

        vector<int> tin(n), tout(n), depth(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            up[0][u] = (p == -1 ? u : p);

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer - 1;
        };

        dfs(0, -1);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n + 1; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto pointQuery = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        vector<int> rootMask(n, 0);

        function<void(int, int, int)> build = [&](int u, int p, int m) {
            rootMask[u] = m ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v != p) build(v, u, rootMask[u]);
            }
        };

        build(0, -1, 0);

        for (int u = 0; u < n; u++) {
            add(tin[u], 1 << (s[u] - 'a'));
            add(tout[u] + 1, 1 << (s[u] - 'a'));
        }

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                if (s[u] != c) {
                    int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                    add(tin[u], delta);
                    add(tout[u] + 1, delta);

                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);
                int mu = pointQuery(tin[u]);
                int mv = pointQuery(tin[v]);

                int pathMask = mu ^ mv ^ (1 << (s[w] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};