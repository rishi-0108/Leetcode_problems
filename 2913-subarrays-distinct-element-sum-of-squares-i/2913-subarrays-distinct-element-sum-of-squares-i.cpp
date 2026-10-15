class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mp;
            int uniqueEle = 0;
            for (int j = i; j < nums.size(); j++) {
                int ele = nums[j];
                if (mp.find(ele) == mp.end())
                    uniqueEle++;

                mp[ele]++;

                ans += pow(uniqueEle, 2);
            }
        }
        return ans;
    }
};