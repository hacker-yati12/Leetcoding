class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
            return 1;
        long long ans = 1;
        int ctr = 1;
        while(--n) {
            ans += 4*(long long)(ctr++);
        }
        return ans;
    }
};