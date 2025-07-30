class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int i=0, j=0;
        while(nums[i]!=maxi) i++;
        int ans = 1;
        while(i<n) {
            j = i;
            while(j<n && nums[j]==maxi) j++;
            ans = max(ans, j-i);
            i = j;
            while(i<n && nums[i]!=maxi) i++;
        }
        return ans;
    }
};