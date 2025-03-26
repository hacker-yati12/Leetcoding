class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        n = arr.size();
        sort(arr.begin(), arr.end());
        int mid = arr[n/2];
        int ans = 0;
        for(auto &it: arr) {
            if(abs(mid-it)%x != 0)
                return -1;
            ans += abs(mid-it)/x;
        }
        return ans;
    }
};