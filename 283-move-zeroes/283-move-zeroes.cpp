class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev=0,curr=0;
        while(curr<nums.size())
        {
            if(nums[curr]!=0)
            {
                swap(nums[curr],nums[prev]);
                curr++;
                prev++;
            }
            else
                curr++;
        }
    }
};