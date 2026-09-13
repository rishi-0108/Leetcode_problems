class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxi=0;
        for(int down=-(n-1);down<=(n-1);down++){
            for(int right=-(n-1);right<=(n-1);right++){
                int overlap=0;
                for(int row=0;row<n;row++){
                    for(int col=0;col<n;col++){
                        if(img1[row][col]==1){
                            int newrow=row+down;
                            int newcol=col+right;
                            if(newrow >= 0 && newrow < n &&
                               newcol >= 0 && newcol < n &&
                               img2[newrow][newcol] == 1){
                                    overlap++;
                            }
                        }
                    }
                }
                maxi=max(maxi,overlap);
            }
        }
        return maxi;
    }
};