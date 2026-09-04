class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        /*
        brute force :
        int maxi=INT_MIN;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            int mini=INT_MAX;
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
            }
            maxi=max(maxi,nums[i]);
            if((maxi-mini)<=k){
                return i;
            }
        }
        return -1;
        */

        // optimal prefix sum 
        int n=nums.size();
        vector<int> mini(n),maxi(n);
        mini[n-1]=nums[n-1];
        maxi[0]=nums[0];
        for(int i=1;i<n;i++){
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if((maxi[i]-mini[i])<=k)
            return i;
        }
        return -1;
    }
};