
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> freq(100001, 0);
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (k >= total) return 0;

        int level = 100000;

        while (k > 0 && level > 0) {
            long long count = freq[level];

            if (count == 0) {
                level--;
                continue;
            }

            long long next = level - 1;
            long long cost = count;

            if (k >= cost) {
                freq[next] += count;
                freq[level] = 0;
                k -= cost;
                level--;
            } else {
                long long reduceEach = k / count;
                long long remainder = k % count;

                freq[level] -= count;
                freq[level - 1] += remainder;
                freq[level - reduceEach] += count - remainder;

                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
