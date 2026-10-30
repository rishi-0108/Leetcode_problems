class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][count] = minimum cost to reach node
        // with count consecutive occurrences of its label.
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();

            if (cost != dist[u][count]) continue;

            if (u == n - 1) return (int)cost;

            for (auto [v, w] : adj[u]) {
                int nextCount;

                if (labels[u] == labels[v]) {
                    nextCount = count + 1;
                } else {
                    nextCount = 1;
                }

                if (nextCount > k) continue;

                long long nextCost = cost + w;

                if (nextCost < dist[v][nextCount]) {
                    dist[v][nextCount] = nextCost;
                    pq.push({nextCost, v, nextCount});
                }
            }
        }

        return -1;
    }
};