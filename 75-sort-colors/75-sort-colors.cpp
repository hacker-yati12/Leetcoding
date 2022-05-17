class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ct0=0,ct1=0,ct2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                ct0++;
            if(nums[i]==1)
                ct1++;
            if(nums[i]==2)
                ct2++;
        }
        for(int i=0;i<ct0;i++)
            nums[i]=0;
        for(int i=ct0;i<ct0+ct1;i++)
            nums[i]=1;
        for(int i=ct0+ct1;i<ct0+ct1+ct2;i++)
            nums[i]=2;
        return;
    }
};