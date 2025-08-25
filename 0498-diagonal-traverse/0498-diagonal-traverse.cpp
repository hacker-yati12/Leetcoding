class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0, j = 0;
        vector<int> ans;
        while(i < m || j < n) {
            ans.push_back(mat[i][j]);
            if((i+j) % 2 == 0) {
                if(i>0 && j < n-1) {
                    i--;
                    j++;
                } else if (j < n-1) {
                    j++;
                } else
                    i++;
            } else {
                if(i < m-1 && j >0) {
                    i++;
                    j--;
                } else if(i < m-1) {
                    i++;
                } else
                    j++;
            }
            if(i==m || j==n)
                break;
        }
        return ans;
    }
};