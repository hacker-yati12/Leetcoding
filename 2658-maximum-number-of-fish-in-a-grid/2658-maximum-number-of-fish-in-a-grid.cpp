class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>>visited(m, vector<int>(n, false));
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int val = 0;
                queue<pair<int, int>> q;
                if(grid[i][j]>0 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                while(!empty(q)) {
                    auto &[x, y] = q.front();
                    q.pop();
                    val += grid[x][y];
                    for(auto &[dx, dy]: dir) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>0 && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                } 
                ans = max(ans, val);               
            }
        }
        return ans;
    }
};