class Solution {
private:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
        vector<int> xdir = {0, 0, 1, -1}, ydir = {1, -1, 0, 0};
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(isValid(nx, ny, heights.size(), heights[0].size()) && 
                    !vis[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visPac(m, vector<bool> (n, false)), visAtl(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            q.push({0, i});
            visPac[0][i] = true;
        }
        for(int i = 1; i < m; i++) {
            q.push({i, 0});
            visPac[i][0] = true;
        }
        bfs(heights, q, visPac);

        q = queue<pair<int, int>>();
        for(int i = 0; i < n; i++) {
            q.push({m-1, i});
            visAtl[m-1][i] = true;
        }
        for(int i = 0; i < m - 1; i++) {
            q.push({i, n - 1});
            visAtl[i][n - 1] = true;
        }
        bfs(heights, q, visAtl);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visPac[i][j] && visAtl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};