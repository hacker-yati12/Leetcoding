class Solution {
private:
    bool dfs(int i, vector<vector<int>>& graph, unordered_map<int, bool>& mp) {
        if(mp.find(i) != mp.end())
            return mp[i];
        mp[i] = false;
        for(auto &x: graph[i]) {
            if(!dfs(x, graph, mp))
                return false;
        }
        mp[i] = true;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> mp;
        vector<int> ans;
        for(int i=0; i<graph.size(); i++) {
            if(dfs(i, graph, mp))
                ans.push_back(i);
        }
        return ans;
    }
};