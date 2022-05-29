class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
               max=nums[i];
            if(nums[i]==max)
                count++;            
            else
                count--;
        }
        return max;
    }
};