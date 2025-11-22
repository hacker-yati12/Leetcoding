class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,minVal=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minVal=min(prices[i],minVal);
                if(prices[i]>minVal)
                   profit=max(profit,prices[i]-minVal);
        }
         return profit;
        
    }
};