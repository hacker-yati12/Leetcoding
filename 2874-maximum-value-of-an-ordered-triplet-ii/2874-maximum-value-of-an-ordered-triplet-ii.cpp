class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxdiff = 0;
        int maxi = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, maxdiff*nums[i]);
            maxdiff = max(maxdiff, maxi - nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return ans;
    }
};