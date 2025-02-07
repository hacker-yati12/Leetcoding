class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> clr;
        vector<int> ans;
        for(auto q: queries) {
            int x = q[0];
            int y = q[1];
            if(mp[x]!=0) {
                clr[mp[x]]--;
                if(clr[mp[x]]==0)
                    clr.erase(mp[x]);
            }
            mp[x] = y;
            clr[y]++;
            ans.push_back(clr.size());
        }
        return ans;
    }
};