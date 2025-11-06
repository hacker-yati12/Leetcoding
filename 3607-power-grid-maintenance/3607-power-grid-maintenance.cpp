#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &x : connections)
            dsu.unite(x[0], x[1]);

        // group nodes by component
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> comp;
        for (int i = 1; i <= c; ++i)
            comp[dsu.find(i)].push(i);

        unordered_set<int> vis;
        vector<int> res;

        for (auto &q : queries) {
            if (q[0] == 1) {
                if(vis.find(q[1])==vis.end()){
                res.push_back(q[1]);
                continue;

                }
                int par = dsu.find(q[1]);
                auto &pq = comp[par];

                // remove visited nodes from heap top
                while (!pq.empty() && vis.count(pq.top()))
                    pq.pop();

                if (pq.empty()) res.push_back(-1);
                else res.push_back(pq.top());
            } else {
                vis.insert(q[1]);
            }
        }
        return res;
    }
};
