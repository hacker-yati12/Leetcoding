class Solution {
public:
    int binaryGap(int n) {
        if (__builtin_popcount(n) <= 1)
            return 0;

        long ans = 1;
        long ct = 1;
        while(!(n & 1))
            n >>= 1;
        while(n >>= 1) {
            if (n & 1) {
                ans = max(ans, ct);
                ct = 1;
            } else
                ct++;
        }
        return ans;
    }
};