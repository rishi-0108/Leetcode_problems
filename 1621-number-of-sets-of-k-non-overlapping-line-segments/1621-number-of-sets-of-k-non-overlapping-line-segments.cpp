class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        for (int k = 1; k <= K; k++) {
            long long suffix = 0;
            dp[k][n] = 0;
            dp[k][n - 1] = 0;
            for (int i = n - 2; i >= 0; i--) {
                suffix = (suffix + dp[k - 1][i + 1]) % MOD;
                int skip = dp[k][i + 1];
                int take = suffix;
                dp[k][i] = (skip + take) % MOD;
            }
        }
        return dp[K][0];
    }
};