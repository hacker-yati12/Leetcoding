class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> x_axis, y_axis;
        for (auto &x: buildings) {
            x_axis[x[0]].insert(x[1]);
            y_axis[x[1]].insert(x[0]);
        }
        int ans = 0;
        for (auto &x: buildings) {
            auto y1 = y_axis[x[1]].find(x[0]);
            auto x1 = x_axis[x[0]].find(x[1]);
            if (x1 != x_axis[x[0]].begin() && x1 != prev(x_axis[x[0]].end()) && y1 != y_axis[x[1]].begin() && y1 != prev(y_axis[x[1]].end()))
                ans++;
        }
        return ans;
    }
};