class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b, ll limit) {
        ll g = gcd(a, b);
        
        if (a / g > limit / b)
            return limit + 1;
        
        return (a / g) * b;
    }

    ll count(ll x, vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            ll curLCM = 1;
            bool valid = true;
            int bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    curLCM = lcm(curLCM, coins[i], x);
                    if (curLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
                continue;
            ll cnt = x / curLCM;
            if (bits & 1)
                ans += cnt;
            else
                ans -= cnt;
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());
        ll low = 1;
        ll high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};