class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long power = n;
        if (power < 0)
            power *= -1;
        while (power > 0) {
            if (power % 2 == 0) {
                x = x * x;
                power = power / 2;

            } else {
                ans *= x;
                power--;
            }
        }
        if (n >= 0)
            return ans;
        else
            return 1.0 / ans;
    }
};