class Solution {
    void solve(unordered_map<char, int>& mp, int &ans) {
        for(auto &x: mp) {
            if(x.second > 0) {
                x.second--;
                solve(mp, ++ans);
                x.second++;
            }                
        }
        return;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;
        for(char &x: tiles)
            mp[x]++;
        int ans = 0;
        solve(mp, ans);
        return ans;
    }
};