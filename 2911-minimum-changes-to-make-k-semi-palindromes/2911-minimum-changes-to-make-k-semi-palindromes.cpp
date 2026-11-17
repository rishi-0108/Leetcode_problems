
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute cost of converting every substring
        // into a semi-palindrome
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Each group contains indices with
                    // the same remainder modulo d
                    for (int r = 0; r < d; r++) {
                        int left = i + r;
                        int right = i + r + ((len - 1 - r) / d) * d;

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // DP
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int t = 2 * (p - 1); t <= i - 2; t++) {

                    dp[i][p] = min(
                        dp[i][p],
                        dp[t][p - 1] + cost[t][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
