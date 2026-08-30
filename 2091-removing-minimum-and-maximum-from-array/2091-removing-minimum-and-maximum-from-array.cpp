class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN;
        int minind=-1,maxind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minind=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxind=i;
            }
        }
        int lefthatana=0;
        int righthatana=0;
        int leftright=0;
        if(maxind>minind){
            righthatana=n-minind;
            lefthatana=maxind+1;
            leftright=(minind+1) + (n-maxind);
        }
        else{
            righthatana=n-maxind;
            lefthatana=minind+1;
            leftright=(maxind+1) + (n-minind);
        }
        int ans=min({lefthatana,righthatana,leftright});
        return ans;
    }
};