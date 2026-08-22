class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int x=n;
        while(x!=0){
            int d=x%10;
            sum+=d;
            product*=d;
            x/=10;
        }
        int sum_p_s=sum+product;
        if(n%sum_p_s == 0)return true ;
        else return false;
    }
};