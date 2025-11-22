class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = max(0, curr + nums[i]);
            ans = max(ans, curr);
        }
        if (*max_element(nums.begin(), nums.end()) < 0)
            return *max_element(nums.begin(), nums.end());
        return ans;
    }
};