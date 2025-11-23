class Solution {
public:
    double myPow(double x, long long int n) {
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        double res = 1;
        double curr = x;

        while (n > 0) {
            if (n % 2 == 1)
                res = res * curr;
            curr = curr * curr;
            n = n / 2;
        }
        return res;
    }
};