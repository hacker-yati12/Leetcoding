class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto x: edges) {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        int comp = 0;
        dfs(0, -1, adj, values, k, comp);
        return comp;
    }

    long long dfs(int curr, int par, unordered_map<int, unordered_set<int>>& adj, vector<int>& values, int k, int &comp) {
        long long sum = 0;
        for(auto x: adj[curr]) {
            if(x!=par)
                sum += dfs(x, curr, adj, values, k, comp);
        }
        sum += values[curr];
        if(sum%k == 0) {
            comp++;
            sum = 0;
        }
        return sum;
    }
};