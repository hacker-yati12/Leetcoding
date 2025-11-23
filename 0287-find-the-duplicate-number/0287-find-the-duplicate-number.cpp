class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            while (nums[i] != i+1) {
                int elem = nums[i];
                int pos = elem - 1;
                if (elem != nums[pos])
                    swap(nums[i], nums[pos]);
                else 
                    return nums[i];
            }
            i++;
        }
        return 0;
    }
};