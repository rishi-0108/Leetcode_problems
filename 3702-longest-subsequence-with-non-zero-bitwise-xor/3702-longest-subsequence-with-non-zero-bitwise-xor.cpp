class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ls=0;
        int xorval=0;
        for(int i=0;i<nums.size();i++){
            xorval^=nums[i];
        }
        if(xorval!=0)return nums.size();
        for(int x:nums){
            if(x!=0)return nums.size()-1;
        }
        return 0;
    }
};