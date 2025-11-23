class Solution {
public:
    int uniquePaths(int m, int n) {
        m = m - 1;
        n = n - 1;
        int sz = m + n;
        long long res = 1;
        int j = 1;
        for (int i = m + 1; i <= sz; i++, j++) {
            res *= 1LL * i;
            res /= j;
        }
        return res;
    }
};