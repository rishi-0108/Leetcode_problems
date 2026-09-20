class Solution {
public:
    int reverseDegree(string s) {
        int revDegree=0;
        for(int i=0;i<s.size();i++){
            int indexReverse = 26 - (s[i] - 96) + 1;
            revDegree += ( indexReverse * (i+1) );
        }
        return revDegree;
    }
};