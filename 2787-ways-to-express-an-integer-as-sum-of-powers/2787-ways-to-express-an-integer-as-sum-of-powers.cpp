class Solution {
public:
    int numberOfWays(int n, int x) {
        using ll = long long;
        ll e = pow(n, 1.0/x) + 1;

        const ll mod = 1e9+7;
        vector<vector<ll>> dp(e+1, vector<ll> (n+1, 0));
        for(int i=0; i<= e; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= e; i++) {
            for(int j = 1; j <= n; j++) {
                if(j >= pow(i, x))
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-pow(i, x)]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[e][n];
    }
};