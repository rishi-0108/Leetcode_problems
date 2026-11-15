class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        int odd = 0, even = 1;
        int prefixSum = 0;
        int ans = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                ans += odd;
                even++;
            } 
            else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};