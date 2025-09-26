class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n-3; i++) {
            for(int j = i + 1; j <= n-2; j++) {
                int sum = nums[i] + nums[j];
                int third = lower_bound(nums.begin() + j + 1, nums.end(), sum) - nums.begin() - 1;
                if(third > j)
                    ans += third - j;
            }
        }
        return ans;
    }
};