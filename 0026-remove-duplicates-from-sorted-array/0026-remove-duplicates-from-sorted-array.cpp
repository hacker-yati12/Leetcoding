class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        int ans = 1;
        while(j < n) {
            while(j < n && nums[j] == nums[i]) j++;
            ++i;
            if (i < n && j < n) {
                nums[i] = nums[j];
                ++ans;
            }
            ++j;
        }
        return ans;
    }
};