class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int> r(m), c(n);
        for(int i=0;i<arr.size();i++){
            auto &[row, col] = mp[arr[i]];
            r[row]++;
            c[col]++;
            if(r[row] == n || c[col]==m)
                return i;
        }
        return -1;
    }
};