class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> mp1,mp2;
        for(auto x:word1)
            mp1[x]++;
        
        for(auto x:word2)
            mp2[x]++;
        
        for(auto x:mp1)
            if(mp2[x.first]==0)
                return false;
        
        for(auto x:mp2)
            if(mp2[x.first]==0)
                return false;
        
        if(mp1==mp2)
            return true;
        
        vector<int> v1,v2;
        for(auto x:mp1)
            v1.push_back(x.second);
        
        sort(v1.begin(),v1.end());
        
        for(auto x:mp2)
            v2.push_back(x.second);
        
        sort(v2.begin(),v2.end());
        
        if(v1==v2)
            return true;
        
        return false;
    }
};