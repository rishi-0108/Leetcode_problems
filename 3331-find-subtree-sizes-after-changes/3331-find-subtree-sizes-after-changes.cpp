
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Step 1: Build original tree
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Step 2: Build modified tree
        vector<vector<int>> newTree(n);

        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {

            int ch = s[u] - 'a';

            // Save previous ancestor of this character
            int prev = last[ch];

            // Current node becomes the latest ancestor
            last[ch] = u;

            for (int v : adj[u]) {

                int p = last[s[v] - 'a'];

                // No matching ancestor found
                if (p == -1) {
                    p = u;
                }

                // Add edge in modified tree
                newTree[p].push_back(v);

                // Continue DFS on original tree
                dfs(v);
            }

            // Restore previous ancestor
            last[ch] = prev;
        };

        dfs(0);

        // Step 3: Calculate subtree sizes
        vector<int> ans(n, 1);

        function<int(int)> dfsSize = [&](int u) {

            for (int v : newTree[u]) {
                ans[u] += dfsSize(v);
            }

            return ans[u];
        };

        dfsSize(0);

        return ans;
    }
};
