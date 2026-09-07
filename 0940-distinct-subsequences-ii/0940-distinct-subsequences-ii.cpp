class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        long long dp = 1; // counts distinct subsequences including empty subsequence
        vector<long long> last(26, 0); // dp value just before each char's most recent occurrence
        
        for (char ch : s) {
            int idx = ch - 'a';
            long long newDp = (2 * dp % MOD - last[idx] + MOD) % MOD;
            last[idx] = dp;      // store dp *before* this update
            dp = newDp;
        }
        
        return (int)((dp - 1 + MOD) % MOD); // remove the empty subsequence
    }
};