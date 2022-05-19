class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        if(nums.size()==1)
            return 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])                       
              continue;
            else
            {
                k++;
                nums[k]=nums[i];
            }
        }
        return k+1; 
    }
};