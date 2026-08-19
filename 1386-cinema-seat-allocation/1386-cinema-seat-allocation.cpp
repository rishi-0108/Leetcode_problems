class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> v;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int seat=reservedSeats[i][1];
            if(v.find(row)==v.end()){
                v[row]=vector<bool>(10,false);
            }
            v[row][seat-1]=true;
        }
        long long ans = 2LL * (n-v.size());
        for(auto& p:v){
            vector<bool>& seats=p.second;
            bool left = !seats[1] && !seats[2] && !seats[3] && !seats[4];
            bool middle = !seats[3] && !seats[4] && !seats[5] && !seats[6];
            bool right = !seats[5] && !seats[6] && !seats[7] && !seats[8];

            if(left && right){
                ans+=2;
            }
            else if(left || right || middle){
                ans+=1;
            }
        }
        return ans;
    }
};