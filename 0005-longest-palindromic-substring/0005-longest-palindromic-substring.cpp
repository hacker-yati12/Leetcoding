class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        string ans = "";
        int len = 1;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans += s[i];
                ans += s[i+1];
            }
        }

        for(int i = 0; i < n-1; i++) {
            for(int j = i+2; j < n; j++) {
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    if(j - i >= len) {
                        len = j-i+1;
                        ans = s.substr(i, len);
                    }
                }                
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return (ans=="")?ans+s[0]:ans;
    }
};