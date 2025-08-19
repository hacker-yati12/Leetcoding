class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                int j = i;
                while(j < nums.size() && nums[j] == 0) j++;
                ans += ((long long)(j-i) * (j-i+1))/2;
                i = j;
            }
        }
        return ans;
    }
};