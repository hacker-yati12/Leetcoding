class Solution {
public:
    unordered_map<int, unordered_set<int>> adjlist;
    vector<int> par;
    vector<int> nodeval;
    unordered_map<int, int> comp;
    vector<bool> vis;

    void dfs(int node, int parent, int &ans) {
        vis[node] = true;
        for(auto &x: adjlist[node]) {
            if(!vis[x]) {
                par[x] = parent;
                ans = ans & nodeval[x];
                dfs(x, parent, ans);
            }
        }
        return;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
        nodeval.assign(n, INT_MAX);
        vis.assign(n, false);
        for(auto &x: edges) {
            adjlist[x[0]].insert(x[1]);
            adjlist[x[1]].insert(x[0]);

            nodeval[x[0]] &= x[2];
            nodeval[x[1]] &= x[2];
        }
        for(int i=0; i<n; i++) {
            int ans = nodeval[i];
            if(!vis[i]) {
                dfs(i, i, ans);
                comp[i] = ans;
            }
        }
        for(auto x: par)
            cout<<x<<" ";
        vector<int> sol;
        for(auto &x: query) {
            if(par[x[0]] == par[x[1]])
                sol.push_back(comp[par[x[0]]]);
            else
                sol.push_back(-1);
        }
        return sol;
    }
};