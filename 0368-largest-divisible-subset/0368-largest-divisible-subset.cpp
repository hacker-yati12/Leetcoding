class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);
        int maxi = 0;
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                if(nums[j]%nums[i] == 0 && dp[j]<dp[i]+1) {
                    dp[j] = dp[i]+1;
                    prev[j] = i;

                    if(dp[j] > dp[maxi])
                        maxi = j;
                }
            }
        }
        vector<int> ans;
        for(int i = maxi; i>=0; i=prev[i]) {
            ans.push_back(nums[i]);
            if(prev[i] == -1)
                break;
        }
        return ans;
    }
};