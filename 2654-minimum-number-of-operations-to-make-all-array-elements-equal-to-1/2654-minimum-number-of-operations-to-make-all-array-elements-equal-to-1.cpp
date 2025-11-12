class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int ones = 0;
        for(int i = 0; i < n - 1; i++) {
            int curr = nums[i];
            if (nums[i] == 1)
                ones++;
            for(int j = i + 1; j < n; j++) {
                curr = gcd(curr, nums[j]);
                if(curr == 1) {
                    mini = min(mini, j - i + 1);
                }
            }
        }
        if(nums[n-1] == 1)
            ones++;
        if(mini == INT_MAX)
            return -1;
        else
            return n - 1 + mini - 1 - ones;
    }
};