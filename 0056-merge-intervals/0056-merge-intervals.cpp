class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int st = intervals[0][0];
        int ed = intervals[0][1];
        int i = 1;
        int n = intervals.size();
        while(i < n) {
            while(i < n && intervals[i][0] <= ed) {
                ed = max(ed, intervals[i][1]);
                i++;
            }
            ans.push_back({st, ed});
            if(i < n) {
                st = intervals[i][0];
                ed = intervals[i][1];
            }
        }
        return ans;
    }
};