class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& newGrid, vector<vector<bool>>& vis, int i, int j, int gp, vector<int>& gIdx) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i ,j});
        newGrid[i][j] = gp;
        vis[i][j] = true;
        int curr = 1;
        while(!q.empty()) {
            auto [ii, jj] = q.front();
            q.pop();
            for(auto &[d1, d2]: dir) {
                int newi = ii + d1;
                int newj = jj + d2;
                if(newi>=0 && newj>=0 && newi<m && newj<n && !vis[newi][newj] && grid[newi][newj]==1) {
                    ++curr;
                    vis[newi][newj] = true;
                    q.push({newi, newj});
                    newGrid[newi][newj] = gp;
                }
            }
        }
        gIdx.push_back(curr);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> newGrid(m, vector<int> (n, 0));
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<int> gIdx = {0};
        int gp = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    bfs(grid, newGrid, vis, i, j, gp, gIdx);
                    ++gp;
                }
            }
        }
        int ans = 0;
        bool ent = false;
        for(int t1=0; t1<m; t1++) {
            for(int t2=0; t2<n; t2++) {
                int curr = 1;
                if(grid[t1][t2] == 0) {
                    unordered_set<int> st;
                    ent = true;
                    if(t1-1>=0) {
                        if(!st.count(newGrid[t1-1][t2])) {
                            curr += cpy[newGrid[t1-1][t2]];
                            st.insert(newGrid[t1-1][t2]);
                        }
                    }
                    if(t1+1<m) {
                        if(!st.count(newGrid[t1+1][t2])) {
                            curr += cpy[newGrid[t1+1][t2]];
                            st.insert(newGrid[t1+1][t2]);
                        }
                    }
                    if(t2-1>=0) {
                        if(!st.count(newGrid[t1][t2-1])) {
                            curr += cpy[newGrid[t1][t2-1]];
                            st.insert(newGrid[t1][t2-1]);
                        }
                    }
                    if(t2+1<n) {
                        if(!st.count(newGrid[t1][t2+1])) {
                            curr += cpy[newGrid[t1][t2+1]];
                            st.insert(newGrid[t1][t2+1]);
                        }
                    }
                }
                ans = max(ans, curr);
            }
        }
        if(!ent)
            return m*n;
        return ans;
    }
};