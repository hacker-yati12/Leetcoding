class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int left=target-nums[i]-nums[j];
                int low=j+1;
                int high=nums.size()-1;
                while(low<high)
                {                   
                    if(nums[low]+nums[high]>left)
                        high--;
                    else if(nums[low]+nums[high]<left)
                        low++;
                    else
                    {
                       vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[low]);
                        vec.push_back(nums[high]);
                        ans.insert(vec);
                        low++;
                        high--;                        
                    }                    
                }
            }
        }
        vector<vector<int>> v;
        for(auto x:ans)
            v.push_back(x);
        return v;
    }
};