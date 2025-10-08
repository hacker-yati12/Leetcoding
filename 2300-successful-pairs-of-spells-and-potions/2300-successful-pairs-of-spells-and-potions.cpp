class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;
        for(auto &x: spells) {
            double val = success/(x*1.0);
            int idx = lower_bound(potions.begin(), potions.end(), val) - potions.begin();
            ans.push_back(n - idx);
        }
        return ans;
    }
};