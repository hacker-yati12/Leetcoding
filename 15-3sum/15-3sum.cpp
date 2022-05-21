class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
       
        if(nums.size()<3)
            return ans;
         sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]>0)
                    high--;
                else if(nums[i]+nums[low]+nums[high]<0)
                    low++;
                else
                {
                    vector<int> p;
                    p.push_back(nums[i]);
                    p.push_back(nums[low]);
                    p.push_back(nums[high]);
                    ans.push_back(p);
                    
                    low++;
                    high--;
                    
                    while(low<high && nums[low]==nums[low-1])
                        low++;
                    
                    while(low<high && nums[high]==nums[high+1])
                        high--;
                }
            }
        }
        return ans;
    }
};