class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> adj;
        for(int i=0; i<n-1; i++)
            adj[i].insert(i+1);
        vector<int> ans;
        for(auto x: queries) {
            vector<bool> vis(n, false);
            adj[x[0]].insert(x[1]);
            queue<int> q;
            q.push(0);
            vis[0] = true;
            int dist = 0;
            bool flag = false;
            while(!q.empty()) {
                int sz = q.size();
                for(int i=0; i<sz; i++) {
                    int node = q.front();
                    q.pop();
                    if(node == n-1) {
                        ans.push_back(dist);
                        flag = true;
                        break;
                    }
                    if(flag)
                        break;
                    for(auto &y: adj[node]) {
                        if(!vis[y]) {
                            q.push(y);
                            vis[y] = true;
                        }
                    }
                }
                dist++;
            }
        }
        return ans;
    }
};