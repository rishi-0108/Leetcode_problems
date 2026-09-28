class Solution {
public:
    int maxDepth(string s) {
        int level = 0;
        int max=0;
        for(char ch:s){
            if(ch=='('){
                level++;
                max=(level>max)?level:max;
            }
            else if(ch==')'){
                level--;
            }
        }
        return max;
    }
};