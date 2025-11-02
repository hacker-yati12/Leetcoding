class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(auto x: guards) {
            visited[x[0]][x[1]] = 1;
        }
        for(auto x: walls) {
            visited[x[0]][x[1]] = 2;
        }

        for(auto x: guards) {
            int i = x[0];
            int j = x[1];

            while(--i>=0 && (visited[i][j] != 2 && visited[i][j] != 1)) {
                visited[i][j] = 3;
            }
            i = x[0];
            while(++i<m && (visited[i][j] != 2 && visited[i][j] != 1)) {
                visited[i][j] = 3;
            }
            i = x[0];
            while(--j>=0 && (visited[i][j] != 2 && visited[i][j] != 1)) {
                visited[i][j] = 3;                
            }
            j = x[1];
            while(++j<n && (visited[i][j] != 2 && visited[i][j] != 1)) {
                visited[i][j] = 3;
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(visited[i][j] == 0) 
                    ans++;
            }
        }
        return ans;
    }
};