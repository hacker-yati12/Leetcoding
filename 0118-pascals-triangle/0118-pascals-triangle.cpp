class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for (int i = 0; i < numRows; i++) {
            tmp.clear();
            tmp.resize(i+1);
            int j = 0, k = i;
            tmp[j] = 1;
            tmp[k] = 1;
            for (int l = j+1; l < k; l++) {
                tmp[l] = ans[i-1][l] + ans[i-1][l-1];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};