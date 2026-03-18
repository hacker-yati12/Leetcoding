class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if (grid[0][0] > k)
            return 0;
        int ans = 0;
        vector<vector<long long>> vec(grid.size(), vector<long long> (grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vec[i][j] = grid[i][j];
                if (i > 0)
                    vec[i][j] += vec[i-1][j];
                if (j > 0)
                    vec[i][j] += vec[i][j-1];
                if (i > 0 && j > 0)
                    vec[i][j] -= vec[i-1][j-1];
                
                if (vec[i][j] <= k)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};