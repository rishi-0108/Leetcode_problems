#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = true if s[l...r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Build palindrome DP
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r]) {
                    if (len == 2)
                        pal[l][r] = true;
                    else
                        pal[l][r] = pal[l + 1][r - 1];
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using s[0 ... i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't use a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int l = 0; l < i; l++) {
                int len = i - l;

                if (len >= k && pal[l][i - 1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};