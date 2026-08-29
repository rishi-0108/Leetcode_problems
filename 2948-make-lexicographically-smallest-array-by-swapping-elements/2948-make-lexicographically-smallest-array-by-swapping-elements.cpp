class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int start = 0;
        for(int i = 1; i < v.size(); i++) {
            if(v[i].first - v[i-1].first > limit) {
                vector<int> indices;
                for(int j=start;j<i;j++){
                    indices.push_back(v[j].second);
                }
                sort(indices.begin(),indices.end());
                for(int j=start;j<i;j++){
                    nums[indices[j-start]]=v[j].first;
                }
                start = i;
            }
        }
       vector<int> indices;

        for(int j = start; j < v.size(); j++) {
            indices.push_back(v[j].second);
        }

        sort(indices.begin(), indices.end());

        for(int j = start; j < v.size(); j++) {
            nums[indices[j-start]] = v[j].first;
        }
        return nums;
    }
};