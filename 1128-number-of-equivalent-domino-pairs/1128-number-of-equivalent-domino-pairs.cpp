class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(auto &x: dominoes) {
            int a = (x[0]<x[1])?x[0]:x[1];
            int b = (x[0]>x[1])?x[0]:x[1];
            mp[{a, b}]++;
            ans += mp[{a, b}]-1;
        }
        return ans;
    }
};