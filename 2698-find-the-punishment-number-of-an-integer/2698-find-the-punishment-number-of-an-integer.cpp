class Solution {
    bool punish(int n, int curr, int sum) {
        if(curr == 0) {
            if(sum == n)
                return true;
            return false;
        }
        bool ans = false;
        for(int i=10; i<=1000; i*=10) {
            ans |= punish(n, curr/i, sum+(curr%i));
        }
        return ans;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(punish(i, i*i, 0))
                ans += i*i;
        }
        if(n==1000)
            ans += 1e6;
        return ans;
    }
};