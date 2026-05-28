class Solution {
private:
    void solve (vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int m, int n) {
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            if (a + 1 < m && !vis[a + 1][b] && grid[a + 1][b] == '1') {
                q.push({a + 1, b});
                vis[a + 1][b] = true;
            }
            if (a - 1 >= 0 && !vis[a - 1][b] && grid[a - 1][b] == '1') {
                q.push({a - 1, b});
                vis[a - 1][b] = true;
            }
            if (b + 1 < n && !vis[a][b + 1] && grid[a][b + 1] == '1') {
                q.push({a, b + 1});
                vis[a][b + 1] = true;
            }
            if (b - 1 >= 0 && !vis[a][b - 1] && grid[a][b - 1] == '1') {
                q.push({a, b - 1});
                vis[a][b - 1] = true;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ++ans;
                    solve(grid, vis, i, j, m, n);
                }
            }
        }
        return ans;
    }
};