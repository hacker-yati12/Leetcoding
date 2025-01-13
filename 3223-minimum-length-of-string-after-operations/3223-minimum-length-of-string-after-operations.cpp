class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<int> f(26, 0);
        for(auto &x: s) {
            f[x-'a']++;
        }
        int ans = 0;
        for(auto &x: f) {
            if(x == 0) continue;
            else if(x&1)
                ans++;
            else 
                ans += 2;
        }
        return ans;
    }
};