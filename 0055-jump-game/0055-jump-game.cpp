class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        dp[0] = true;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(i>maxi)
                return false;
            maxi = max(maxi, i+nums[i]);
        }
        if(maxi >= nums.size()-1)
            return true;
        else
            return false;
    }
};