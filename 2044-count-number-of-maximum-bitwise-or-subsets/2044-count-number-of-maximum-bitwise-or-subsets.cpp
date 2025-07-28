class Solution {
private:
    int solve(vector<int>& nums, int maxi, int ops, int i) {
        if(i == nums.size()) 
            return ops==maxi;
        int take = 0, ntake = 0;
        take += solve(nums, maxi, ops | nums[i], i+1);
        ntake += solve(nums, maxi, ops, i+1);
        return take+ntake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);
        int maxi = 0;
        for(auto x: nums)
            maxi |= x;
        
        return solve(nums, maxi, 0, 0);
    }
};