class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sodd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1 && nums1[i]<sodd){
                sodd=nums1[i];
            }
        }
        if(sodd==INT_MAX)return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                nums1[i]-=sodd;
            }
            if(nums1[i]<1)return false;
        }
        return true;
    }
};