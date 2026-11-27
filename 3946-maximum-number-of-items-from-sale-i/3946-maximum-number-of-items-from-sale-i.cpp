class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> cost(n), value(n);

        for (int i = 0; i < n; i++) {
            cost[i] = items[i][1];
            minPrice = min(minPrice, cost[i]);

            value[i] = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    value[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = budget; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
            }
        }

        int ans = 0;

        for (int spent = 0; spent <= budget; spent++) {
            ans = max(ans, dp[spent] + 
                      (budget - spent) / minPrice);
        }

        return ans;
    }
};