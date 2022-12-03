class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        vector<pair<int,char>> pr;
        for(auto x:mp)
        {
            pair<int,char> temp=make_pair(x.second,x.first);
            pr.push_back(temp);
        }
        sort(pr.begin(),pr.end(),greater<>());
        string ans="";
        for(auto x:pr)
            ans+=string(x.first,x.second);
        return ans;
    }
};