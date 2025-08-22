class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int t = -1;
        while(!empty(q)) {
            int sz = q.size();
            while(sz--) {
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                if(x+1 < m && !vis[x+1][y] && grid[x+1][y]==1) {
                    q.push({x+1, y});
                    vis[x+1][y] = true;
                }
                if(y+1 < n && !vis[x][y+1] && grid[x][y+1]==1) {
                    q.push({x, y+1});
                    vis[x][y+1] = true;
                }
                if(x-1 >=0 && !vis[x-1][y] && grid[x-1][y]==1) {
                    q.push({x-1, y});
                    vis[x-1][y] = true;
                }
                if(y-1 >= 0 && !vis[x][y-1] && grid[x][y-1]==1) {
                    q.push({x, y-1});
                    vis[x][y-1] = true;
                }
            }
            t++;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j]==1)
                    return -1;
            }
        }
        return (t==-1)?0: t;
    }
};