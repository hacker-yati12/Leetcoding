class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0, j = 1;
        while (i < n) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            while (j < n && intervals[j][0] <= e) {
                e = max(e, intervals[j][1]);
                j++;
            }
            ans.push_back({s, e});
            i = j;
            ++j;
        }
        return ans;
    }
};