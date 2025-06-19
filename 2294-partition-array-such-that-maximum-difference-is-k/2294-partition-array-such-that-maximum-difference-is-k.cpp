class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        int ans = 1;
        for(int i=1; i<nums.size(); i++) {
            if(abs(nums[i]-curr)>k) {
                ans++;
                curr = nums[i];
            }
        }
        return ans;
    }
};