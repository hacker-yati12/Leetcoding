class Solution {
public:
    void solve(int i, vector<int>& curr, vector<vector<int>>& ans, int tar, vector<int>& candidates) {
        if(i==candidates.size()) {
            if(tar == 0)
                ans.push_back(curr);
            return;
        }
        if(candidates[i]<=tar) {
            curr.push_back(candidates[i]);
            solve(i, curr, ans, tar-candidates[i], candidates);
            curr.pop_back();
        }
        solve(i+1, curr, ans, tar, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, target, candidates);
        sort(ans.begin(), ans.end());
        auto t = unique(ans.begin(), ans.end());
        ans.resize(t-ans.begin());
        return ans;
    }
};