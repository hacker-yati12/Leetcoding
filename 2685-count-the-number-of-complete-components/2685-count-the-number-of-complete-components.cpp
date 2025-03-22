class Solution {
    void dfs(unordered_map<int, vector<int>>& adjlist, vector<bool>& vis, int &v, int &e, int i) {
        vis[i] = true;
        for(auto &x: adjlist[i]) {
            if(!vis[x]) {
                v++;
                dfs(adjlist, vis, v, e, x);
            }                
            e++;
        }
        return;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> adjlist;
        for(auto &x: edges) {
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int v=1, e=0;
            if(!vis[i]) {
                dfs(adjlist, vis, v, e, i);
                if(e == v*(v-1))
                    ans++;
            }
        }
        return ans;
    }
};