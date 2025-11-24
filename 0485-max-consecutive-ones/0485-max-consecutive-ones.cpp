class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while(i < n && nums[i] != 1)
            i++;
        int j = i;
        while(j < n) {
            while(j < n && nums[j] == 1) j++;
            ans = max(ans, j - i);
            while(j < n && nums[j] == 0) j++;
            i = j;
        }
        return ans;
    }
};