class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int c=0;
        int left=0 , right = 0;
        int shortest=INT_MAX;
        int lind=-1,rind=-1;
        for(int right=0;right<s.size();right++){
            if(s[right]=='1')c++;
            while(c>k){
                if(s[left]=='1')c--;
                left++;
            }
            if(c==k){
                while(s[left]=='0')left++;
                if(lind==-1 || shortest>(right-left+1) || ( shortest==(right-left+1) && s.substr(left,right-left+1)<s.substr(lind,rind-lind+1))){
                    shortest=right-left+1;
                    rind=right;
                    lind=left;
                }
            }
        }
        if(lind==-1)return "";
        return s.substr(lind,rind-lind+1);
    }
};