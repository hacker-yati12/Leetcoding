class Solution {
private:
    class Cell {
    public:
        int x;
        int y;
        int ht;
        
        Cell(int ht, int x, int y): ht(ht), x(x), y(y) {}
        bool operator<(const Cell &other) const {
            return other.ht <= ht;
        }
    };

    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

        vector<vector<bool>> vis(n, vector<bool> (n, false));
        priority_queue<Cell> pq;
        pq.push(Cell(grid[0][0], 0, 0));
        vis[0][0] = true;
        int ans = 0;
        while(!pq.empty()) {
            Cell node = pq.top();
            pq.pop();
            int x = node.x;
            int y = node.y;
            int ht = node.ht;
            ans = max(ans, ht);
            if(x == n - 1 && y == n - 1)
                break;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx, ny, n) && !vis[nx][ny]) {
                    pq.push(Cell(grid[nx][ny], nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};