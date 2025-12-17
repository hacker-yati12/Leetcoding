class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e5;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            ans = max(ans, curr);
            curr = max(0, curr);
        }
        return ans;
    }
};