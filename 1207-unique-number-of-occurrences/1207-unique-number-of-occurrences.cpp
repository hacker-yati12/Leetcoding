class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp,mp1;
        for(auto x:arr)
        {
            mp[x]++;            
        }
        
        for(auto x:mp)
        {
            //cout<<x.second<<endl;
            mp1[x.second]++;
            if(mp1[x.second]>1)
                return false;
        }
        return true;
    }
};