class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adjlist(n);
        for(auto &x: roads) {
            adjlist[x[0]].push_back({x[1], x[2]});
            adjlist[x[1]].push_back({x[0], x[2]});
        }
        vector<long long> cost(n, LONG_MAX), moves(n, 0);
        vector<bool> processed(n, false);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        cost[0] = 0;
        moves[0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            auto [cs, node] = q.top();
            q.pop();

            if(processed[node])
                continue;
            processed[node] = true;
            for(auto &x: adjlist[node]) {
                long long ncs = cost[node] + x.second;
                if (!processed[x.first] && ncs == cost[x.first]) {
                    moves[x.first] = (moves[x.first] + moves[node]) % (long long)(1e9+7);
                    q.push({ncs, x.first});
                } else if (!processed[x.first] && ncs < cost[x.first]) {
                    cost[x.first] = ncs;
                    moves[x.first] = moves[node];
                    q.push({ncs, x.first});
                }
            }
        }
        return moves[n-1];
    }
};