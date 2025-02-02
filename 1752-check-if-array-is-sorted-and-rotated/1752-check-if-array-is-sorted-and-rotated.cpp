class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 1;
        int j = 0;
        while(i<nums.size() && nums[i]>=nums[i-1]) {
            i++;
        }
        if(i==nums.size())
            return true;
        while(i+1<nums.size() && nums[i]<=nums[j] && nums[i]<=nums[i+1])
            i++;
        if(i==nums.size()-1)
            return true;
        else 
            return false;
    }
};