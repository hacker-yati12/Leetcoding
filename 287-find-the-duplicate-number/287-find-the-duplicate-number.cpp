class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;//[nums.size()-1];
        int ans;
        for(auto x:nums)
        {
            mp[x]++;
        }
        for(auto y:mp)
        {
            if(y.second>=2)
                ans=y.first;
        }
        return ans;
    }
};