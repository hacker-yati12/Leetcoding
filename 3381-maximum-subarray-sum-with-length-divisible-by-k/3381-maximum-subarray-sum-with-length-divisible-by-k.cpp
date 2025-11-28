class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(k, INT_MAX);
        pref[0] = 0;
        long long curr = 0;
        long long ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            if (pref[(i+1)%k] != INT_MAX)
                ans = max(ans, curr - pref[(i + 1) % k]);
            pref[(i + 1)%k] = min(pref[(i + 1)%k], curr);
        }
        return ans;
    }
};