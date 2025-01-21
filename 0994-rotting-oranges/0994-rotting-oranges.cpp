class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> time(grid.size(), vector<int> (grid[0].size(), 0));
        vector<pair<int, int>> rotten;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2)
                    rotten.push_back({i,j});
                if(grid[i][j]==1 || grid[i][j]==2)
                    time[i][j] = INT_MAX;
            }
        }
        for(auto x: rotten) {
            queue<pair<int, int>> q;
            q.push(x);
            time[x.first][x.second]=0;
            int t=0;
            while(!empty(q)) {
                int sz = q.size()
                for(int i=0; i<sz; i++) {
                    auto [x, y]=q.front();
                    q.pop();
                    if(x+1<m && grid[x+1][y]==1 && t+1<time[x+1][y]) {
                        q.push({x+1, y}); 
                        time[x+1][y] = t+1;
                    }
                    if(x-1>=0 && grid[x-1][y]==1 && t+1<time[x-1][y]) {
                        q.push({x-1, y}); 
                        time[x-1][y] = t+1;
                    }
                    if(y+1<n && grid[x][y+1]==1 && t+1<time[x][y+1]) {
                        q.push({x, y+1}); 
                        time[x][y+1] = t+1;
                    }
                    if(y-1>=0 && grid[x][y-1]==1 && t+1<time[x][y-1]) {
                        q.push({x, y-1}); 
                        time[x][y-1] = t+1;
                    }
                }
                t++;
            }
        }
        int ans = 0;
        for(auto &x: time) {
            for(auto &y: x) {
                ans = max(ans, y);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};