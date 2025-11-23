class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size();
        while (i <= j) {
            int mid = (i + j)/2;
            if (target >= matrix[mid][0])
                i = mid + 1;
            else 
                j = mid - 1;
        }
        i = 0;
        int k = matrix[0].size();
        while (i <= k) {
            int mid = (i+k)/2;
            if (target >= matrix[j][mid])
                i = mid + 1;
            else
                k = mid - 1;
        }
        return matrix[j][k] == target;
    }
};