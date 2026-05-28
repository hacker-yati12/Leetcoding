class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(auto &x: intervals) {
            if (ans.empty() || ans.back()[1] < x[0])
                ans.push_back((x));
            else
                ans.back()[1] = max(ans.back()[1], x[1]);
        }
        return ans;
    }
};