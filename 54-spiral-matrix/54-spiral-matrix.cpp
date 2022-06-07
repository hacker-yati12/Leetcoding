class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        vector<int> ans;
        int rowS=0;
        int colS=0;
        int rowE=m-1;
        int colE=n-1;
        while(1)
        {
            for(int i=colS;i<=colE;i++)
            {
                ans.push_back(matrix[rowS][i]);
            }
            rowS++;
            if(ans.size()==(n*m))
                break;
            for(int i=rowS;i<=rowE;i++)
            {
                ans.push_back(matrix[i][colE]);
            }
            colE--;
            if(ans.size()==(n*m))
                break;
            for(int i=colE;i>=colS;i--)
            {
                ans.push_back(matrix[rowE][i]);
            }
            rowE--;
            if(ans.size()==(n*m))
                break;
            for(int i=rowE;i>=rowS;i--)
            {
                ans.push_back(matrix[i][colS]);
            }
            colS++;
            if(ans.size()==(n*m))
                break;
        }
        return ans;
    }
};