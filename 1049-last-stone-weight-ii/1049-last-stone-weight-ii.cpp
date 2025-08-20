class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if(n==1)
            return stones[0];

        int tot = accumulate(stones.begin(), stones.end(), 0);
        int sum = tot/2;
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(stones[i-1] <= j) 
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-stones[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int i = sum;
        for(; i >= 0; i--) 
            if(dp[n][i]) 
                break;
        return tot - (i*2);
    }
};