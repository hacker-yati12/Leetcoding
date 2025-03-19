class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<=nums.size()-3; i++) {
            if(nums[i]==0) {
                ans++;
                nums[i] = 1;
                nums[i+1] = (nums[i+1]==0)?1:0;
                nums[i+2] = (nums[i+2]==0)?1:0;
            }
        }
        if(nums.back()==0 || nums[n-2]==0)
            return -1;
        else 
            return ans;
    }
};