class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        int ctr = 1;
        while(--n) {
            ans += 4*(long long)(ctr++);
        }
        return ans;
    }
};