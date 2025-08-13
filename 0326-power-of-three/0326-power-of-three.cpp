#include <cmath>
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double val = log(n) / log(3); // change of base
        return fabs(val - round(val)) < 1e-10;
    }
};
