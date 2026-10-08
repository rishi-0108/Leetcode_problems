class Solution {
public:
    string removeOuterParentheses(string s) {
        int level=0;
        string ans="";
        for(char c:s){
            if(c=='('){
                if(level>0){
                    ans=ans+"(";
                }
                level++;
            }
            else if(c==')'){
                level--;
                if(level>0){
                    ans+=")";
                }
            }
        }
        return ans;
    }
};