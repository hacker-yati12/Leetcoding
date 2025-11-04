class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int set1=1,set2=1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
                set1=0;
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    if(matrix[i][j]==0)
                        set2=0;
                }
                if(matrix[i][j]==0)
                matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(i==0)
                {   if(set2==0)
                    {
                        matrix[i][j]=0;
                    }
                }
                else if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(set1==0)
                matrix[i][0]=0;
        }
    }
};