class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smallerThanTarget = 0 , freqTarget = 0;
        for(auto& x : nums){
            if(x <target )smallerThanTarget++;
            else if(target == x)freqTarget++;
        }
        vector<int> ans;
        for(int i=0;i<freqTarget;i++){
            ans.push_back(smallerThanTarget+i);
        }
        return ans;
    }
};