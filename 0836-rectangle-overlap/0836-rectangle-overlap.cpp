class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int bleft1x = rec1[0];
        int bleft1y= rec1[1];
        int tright1x = rec1[2];
        int tright1y= rec1[3];

        int bleft2x = rec2[0];
        int bleft2y= rec2[1];
        int tright2x = rec2[2];
        int tright2y= rec2[3];

        if(tright2x <= bleft1x)return false;
        if(tright2y <= bleft1y)return false;
        if(bleft2x >= tright1x)return false;
        if(bleft2y >= tright1y)return false;

        return true;
    }
};