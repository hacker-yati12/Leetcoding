class Solution {
    set<vector<int>> ans;
    void solve(vector<int>& candidates, vector<int>& curr, int target, int i) {
        if (i == candidates.size() || target <= 0) {
            if (target == 0) 
                ans.insert(curr);
            return;
        }
        curr.push_back(candidates[i]);
        solve(candidates, curr, target - candidates[i], i + 1);
        curr.pop_back();
        solve(candidates, curr, target, i + 1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, curr, target, 0);
        vector<vector<int>> vec;
        for(auto &x: ans) {
            vec.push_back(x);
        }
        return vec;
    }
};