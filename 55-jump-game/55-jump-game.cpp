class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jump = nums[0], i = 0;
        while (i <= jump && i < n) {
            jump = max(jump, i + nums[i]);
            i++;
        }
        if (jump >= n-1) return true;
        return false;
    }
};