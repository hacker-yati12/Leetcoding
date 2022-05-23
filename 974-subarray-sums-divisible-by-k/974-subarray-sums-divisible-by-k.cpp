class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> mp; 
        mp[0]++;
        int sum=0,r;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            r=sum%k;
            if(r<0)
                r+=k;            
            count+=mp[r];
            mp[r]++;
        }        
        return count;
    }
};