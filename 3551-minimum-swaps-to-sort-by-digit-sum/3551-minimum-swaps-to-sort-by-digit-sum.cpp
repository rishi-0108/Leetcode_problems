class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            a[i] = {sum, nums[i]};
            hash[nums[i]] = i;
        }
        sort(a.begin(), a.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first == b.first)
                     return a.second < b.second;
                 else
                     return a.first < b.first;
             });
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != a[i].second) {
                swap(nums[i], nums[hash[a[i].second]]);
                swap(hash[nums[i]], hash[nums[hash[a[i].second]]]);
                swaps++;
            }
        }
        return swaps;
    }
};