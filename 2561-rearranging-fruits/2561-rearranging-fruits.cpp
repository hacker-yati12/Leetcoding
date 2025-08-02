class Solution {
    using ll = long long;
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        ll mn = 1e9;
        ll ans = 0;
        for(auto &x: basket1) {
            mp[x]++;
            mn = min(mn, (ll)x);
        }
        for(auto &x: basket2) {
            mp[x]--; 
            mn = min(mn, (ll)x);
        }
        ll swaps = 0;
        vector<ll> vec;
        for(auto &[k, v]: mp) {
            v = abs(v); 
            if(v%2!=0)
                return -1;
            if(v>0) {
                vec.insert(vec.end(), v/2, k);
            }
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i<vec.size()/2; i++) {
            ans += min(vec[i], 2*mn);
        }
        return ans;
    }
};