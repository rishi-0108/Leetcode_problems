class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> v(101+k,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]=1;
        }
        for(int i=k;i<=100+k;i+=k){
            if(v[i] == 0)
            return i;
        }
        return k;
    }
};