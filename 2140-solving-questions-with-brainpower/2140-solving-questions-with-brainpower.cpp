class Solution {
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        if(i >= questions.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        long long take = questions[i][0] + solve(i+questions[i][1]+1, questions, dp);
        long long ntake = solve(i+1, questions, dp);
        return dp[i] = max(dp[i], max(take, ntake));
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, questions, dp);
    }
};