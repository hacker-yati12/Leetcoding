class Solution {
    int solve(vector<int>& days, vector<int>& costs, int curr, vector<int>& dp) {
        if(curr>days.back()) {
            dp[curr] = 0;
            return 0;
        }
        if(dp[curr] != -1)
            return dp[curr];
        int day = *lower_bound(days.begin(), days.end(), curr);
        int oday = costs[0] + solve(days, costs, day+1, dp);
        int sday = costs[1] + solve(days, costs, day+7, dp);
        int tday = costs[2] + solve(days, costs, day+30, dp);
        return dp[curr] = min(oday, min(sday, tday));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+31, -1);
        return solve(days, costs, days[0], dp);
    }
};