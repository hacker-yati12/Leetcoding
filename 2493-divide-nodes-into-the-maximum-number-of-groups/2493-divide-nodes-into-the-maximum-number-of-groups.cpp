class Solution {
private:
    bool isCompBip(int n, vector<vector<int>>& adj, vector<int>& states, int start) {
        queue<int> q;
        states[start] = 1;
        q.push(start);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]) {
                if(states[nbr] == states[node])
                    return false;
                if(states[nbr]==0) {
                    states[nbr] = (-1)*states[node];
                    q.push(nbr);
                }
            }
        }
        return true;
    }

    bool findComp(int n,vector<vector<int>>& adj) {
        vector<int> states(n+1, 0);
        for(int i=1; i<=n; i++) {
            if(!states[i] && !isCompBip(n, adj, states, i))
                return false;
        }
        return true;
    }

    int bfs(int n, vector<vector<int>>& adj, int st) {
        queue<int> q;
        q.push(st);
        int lvl = 0;
        vector<bool> vis(n+1, false);
        vis[st] = true;
        while(!q.empty()) {
            int sz = q.size();
            ++lvl;
            for(int i=0; i<sz; i++) {
                int node = q.front();
                q.pop();
                for(auto nbr: adj[node]) {
                    if(!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
        return lvl;
    }

    int findmax(int n, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dist, int st) {
        queue<int> q;
        q.push(st);
        visited[st] = true;
        int curr = dist[st];
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]) {
                if(!visited[nbr]) {
                    curr = max(curr, dist[nbr]);
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return curr;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto &x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        if(!findComp(n,adj))
            return -1;

        vector<int> dist(n+1);
        for(int i=1; i<=n; i++) {
            dist[i] = bfs(n, adj, i);
        }
        vector<bool> visited(n+1, false);
        int ans = 0;
        for(int i=1; i<=n;i++) {
            if(!visited[i])
                ans += findmax(n, adj, visited, dist, i);
        }

        return ans;
    }
};