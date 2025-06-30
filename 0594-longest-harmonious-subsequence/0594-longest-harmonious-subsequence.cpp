class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //1,2,2,2,3,3,5,7
        int mini = nums[0], maxi = nums[0];
        int l = 0, r = 0;
        int ans = 0;
        while(r < nums.size()) {
            if(nums[r] - nums[l] <= 1) {
                maxi = nums[r];
                r++;
                if(maxi - mini == 1)
                    ans = max(ans, r-l);
            } else {
                while(l<r && nums[r] - nums[l] > 1) {
                    l++;
                    mini = nums[l];
                }
            }
            if(l==r) {
                r++;
            }
        }
        return ans;
    }
};