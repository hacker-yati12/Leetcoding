class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long curr = 0;
        int ans = 0;
        for(int i = 0; i<nums.size()-1; i++) {
            curr += nums[i];
            total -= nums[i];
            if(curr >= total)
                ans++;
        }
        return ans;
    }
};