class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> prev;
        for(int i=2; i<=numRows; i++) {
            vector<int> curr(i);
            curr[0] = 1;
            curr[curr.size()-1] = 1;
            for(int i = 1; i < curr.size()-1; i++) {
                curr[i] = prev[i-1] + prev[i];
            }
            prev = curr;
            ans.push_back(curr);
        }
        return ans;
    }
};