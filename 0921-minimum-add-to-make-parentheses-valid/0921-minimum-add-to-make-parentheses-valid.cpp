class Solution {
public:
    int minAddToMakeValid(string s) {
        int level = 0 ;
        int ans=0;
        for(auto& ch:s){
            if(ch == '(')level++;
            else level--;

            if(level < 0){
                ans++;
                level++;
            }
        }
        return ans+level;
    }
};