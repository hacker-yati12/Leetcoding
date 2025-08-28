class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //bottom left
        int n = grid.size();
        vector<int> vec;
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; i+j < n ; j++) {
                vec.push_back(grid[i+j][j]);
            }
            sort(vec.rbegin(), vec.rend());
            for(int j = 0; i+j < n ; j++) {
                grid[i+j][j] = vec[j];
            }
            vec.clear();
        } 
        
        //top left
        for(int j = 1; j < n-1; j++) {
            for(int i = 0; i+j < n; i++) {
                vec.push_back(grid[i][i+j]);
            }
            sort(vec.begin(), vec.end());
            for(int i = 0; i+j < n ; i++) {
                grid[i][i+j] = vec[i];
            }
            vec.clear();
        } 
        return grid;
    }
};