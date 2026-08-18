class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left=0,right=k-1;
        while(right!=nums.size()){
            unordered_set<int> seen;
            for(int i=left;i<=right;i++){
                seen.insert(nums[i]);
            }
            for(auto x:seen){
                mp[x]++;
            }
            left++,right++;
        }
        int minfreq=INT_MAX;
        int ans=-1;
        for(auto it:mp){
            if(it.second<minfreq){
                minfreq=it.second;
                ans=it.first;
            }
            else if(it.second==minfreq){
                ans=max(ans,it.first);
            }
        }
        if(minfreq==1)
        return ans;
        else return -1;
    }
};