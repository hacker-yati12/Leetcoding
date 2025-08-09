class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        long double t = log2(n * 1.0);
        return t == (long long)log2(n);
    }
};
