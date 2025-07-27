class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums.size()<3)
            return 0;
        for(int i = 1; i<nums.size()-1; i++) {
            if((nums[i]>nums[i-1] && nums[i]>nums[i+1]) || (nums[i]<nums[i-1] && nums[i]<nums[i+1]))
                ans++;
        }
        return ans;
    }
};