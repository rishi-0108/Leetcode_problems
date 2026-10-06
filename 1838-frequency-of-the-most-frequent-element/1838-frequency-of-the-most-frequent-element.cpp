class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int left = 0;
        int ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // Cost to make every element in the window equal to nums[right]
            long long cost = 1LL * nums[right] * (right - left + 1) - sum;

            while (cost > k) {
                sum -= nums[left];
                left++;

                cost = 1LL * nums[right] * (right - left + 1) - sum;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};