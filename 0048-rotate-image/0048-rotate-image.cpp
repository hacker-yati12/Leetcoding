class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top = 0, bottom = matrix.size() - 1;
        while (top < bottom) {
            for (int i = 0; i < matrix[0].size(); i++) {
                swap(matrix[top][i], matrix[bottom][i]);
            }
            top++;
            bottom--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};