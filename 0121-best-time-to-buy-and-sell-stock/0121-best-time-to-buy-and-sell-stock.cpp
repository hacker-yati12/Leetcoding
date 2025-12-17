class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - prev;
            ans = max(ans, profit);
            prev = min(prev, prices[i]);
        }
        return ans;
    }
};