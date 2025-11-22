class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        int i = n - 2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i+1]) 
                break;
        }
        if (i < 0)
            sort(nums.begin(), nums.end());
        else {
            int j = i+1;
            for (int k = j; k < n; k++) {
                if (nums[k] < nums[j] && nums[k] > nums[i])
                    j = k;
            }
            swap(nums[i], nums[j]);
            sort(nums.begin()+i+1, nums.end());
        }
        return;
    }
};