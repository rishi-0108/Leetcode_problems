
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        // Stores {finishing time, server ID}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        // Initially all servers are available
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Number of requests handled by each server
        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Step 1: Release completed servers
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // Step 2: If no server is available, drop request
            if (available.empty()) {
                continue;
            }

            // Step 3: Find preferred server or next available
            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            // Step 4: Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Step 5: Assign request
            count[server]++;

            available.erase(it);

            // Step 6: Mark server as busy
            busy.push({
                arrival[i] + load[i],
                server
            });
        }

        // Find maximum number of requests handled
        int maxRequests = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
