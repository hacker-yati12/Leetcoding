class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        for(auto &x: nums) {
            if(x%value < 0) {
                mp[(x%value)+value]++;
            } else {
                mp[x%value]++;
            }
        }
        for(auto x: mp)
            cout<<x.first<<" "<<x.second;
        int i = 0;
        for(; i < nums.size(); i++) {
            if(mp[i%value] == 0)
                return i;
            else
                mp[i%value]--;
        }
        return i;
    }
};