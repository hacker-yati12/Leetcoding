class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0], ct = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curr) {
                ct++;
                continue;
            } else {
                ct--;
                if (ct == 0) {
                    curr = nums[i];
                    ct = 1;
                }
            }
        }
        return curr;
    }
};