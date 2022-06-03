class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ans;
        vector<vector<string>> ana;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            ans[temp].push_back(strs[i]);
        }
        for(auto x:ans)
            ana.push_back(x.second);
        return ana;
    }
};