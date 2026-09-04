class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        // int stable=INT_MAX;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            int mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
            }
            maxi=max(maxi,nums[i]);
            if((maxi-mini)<=k){
                // stable=maxi-mini;
                return i;
            }
        }
        return -1;
    }
};