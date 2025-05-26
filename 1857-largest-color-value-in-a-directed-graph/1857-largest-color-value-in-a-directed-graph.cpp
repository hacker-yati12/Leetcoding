class Solution {
    vector<int> topo;
    bool detectCycle(int s, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis)
    {
        if(!vis[s]) {
            vis[s] = 1;
            pathVis[s] = 1;

            for(int x : adj[s]) {
                if(detectCycle(x, adj, vis, pathVis)) {
                    return true;
                }
            }
            topo.push_back(s);
            pathVis[s] = 0;
        } else if(pathVis[s]) {
            return true;
        }
        return false;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges)
    {
        int maxcolor = -1;
        vector<vector<int>> adj(colors.size());

        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        vector<int> vis(adj.size());
        vector<int> pathVis(adj.size());

        for(int i = 0; i <adj.size(); i++) {
            if(!vis[i]) {
                if(detectCycle(i, adj, vis, pathVis)) {
                    return -1;
                }
            }
        }
        vector<vector<int>> dp(adj.size(), vector<int>(26, 0));

        for(int k = topo.size() - 1; k >= 0; k--) {
            int i = topo[k];
            dp[i][colors[i] - 97] += 1;
            maxcolor = max(maxcolor, dp[i][colors[i] - 97]);
            
            for(int x : adj[i]) {
                for(int col = 0; col < 26; col++) {
                    if(dp[x][col] < dp[i][col]) {
                        dp[x][col] = dp[i][col];
                    }
                }
            }
        }
        return maxcolor;
    }
};