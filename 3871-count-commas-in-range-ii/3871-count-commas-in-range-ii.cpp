class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 1st comma: 1,000 onwards
        if (n >= 1000)
            ans += n - 999;

        // 2nd comma: 1,000,000 onwards
        if (n >= 1000000)
            ans += n - 999999;

        // 3rd comma: 1,000,000,000 onwards
        if (n >= 1000000000)
            ans += n - 999999999;

        // 4th comma: 1,000,000,000,000 onwards
        if (n >= 1000000000000LL)
            ans += n - 999999999999LL;

        // 5th comma: 1,000,000,000,000,000 onwards
        if (n >= 1000000000000000LL)
            ans += n - 999999999999999LL;

        return ans;
    }
};