class Solution {
public:
int minMoves(vector<int> &nums){
    int count=0;
    int minimum=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
       if(minimum>nums[i])
           minimum=nums[i];
    }
    for(int i=0;i<nums.size();i++)
        count+=nums[i]-minimum;
    return count;
    }
};