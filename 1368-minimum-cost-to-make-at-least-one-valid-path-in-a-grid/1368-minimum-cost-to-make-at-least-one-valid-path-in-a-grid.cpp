class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));
        queue<tuple<int, int, int>> pq;
        cost[0][0] = 0;
        pq.push({0, 0, 0});
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!empty(pq)) {
            tuple<int, int, int> node = pq.front();
            int c = get<0>(node);
            int i = get<1>(node);
            int j = get<2>(node);
            pq.pop();
            if(cost[i][j]<c) continue;
            for(int d=0; d<4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if(ni>=0 && ni<m && nj>=0 && nj<n) {
                    int cs = (grid[i][j] == d+1)?0: 1;
                    if(c+cs<cost[ni][nj]) {
                        pq.push({c+cs, ni, nj});
                        cost[ni][nj] = c+cs;
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};