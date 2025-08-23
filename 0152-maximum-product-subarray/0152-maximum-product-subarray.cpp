class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int pre = 1, suf = 1;
        for(int i = 0; i < n; i++) {
            pre = (pre==0)? 1 : pre;
            suf = (suf==0)? 1 : suf;

            pre *= nums[i];
            suf *= nums[n - i - 1];
            ans = max({ans, pre, suf});
        }
        return ans;
    }
};