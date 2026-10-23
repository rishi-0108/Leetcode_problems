
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                k |= nums[i];
            }
        }

        if (k == 0) return 0;

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        return ans;
    }
};
