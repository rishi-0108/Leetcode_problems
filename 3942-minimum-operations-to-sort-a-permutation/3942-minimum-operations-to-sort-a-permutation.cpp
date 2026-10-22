class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n)
                inc = false;

            if (nums[i] != (k - i + n) % n)
                dec = false;
        }

        if (inc && k == 0)
            return 0;

        if (!inc && !dec)
            return -1;

        return min(n - k, k + 2);
    }
};