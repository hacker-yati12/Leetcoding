class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int total=0;
        for(auto x:nums)
            total+=x;
        long long int first=0,last=total;
        long long int firstav,lastav,diff,ans=INT_MAX,ans_i;
        for(int i=0;i<nums.size();i++)
        {
            first+=nums[i];
            firstav=first/(i+1);
            last-=nums[i];
            if(i==nums.size()-1)
                lastav=0;
            else
                lastav=last/(nums.size()-i-1);
            //cout<<firstav<<" "<<lastav<<endl;            
            diff=abs(firstav-lastav);
            if(diff<ans)
            {
                ans=min(ans,diff);
                ans_i=i;
            }
        }
        return ans_i;
    }
};