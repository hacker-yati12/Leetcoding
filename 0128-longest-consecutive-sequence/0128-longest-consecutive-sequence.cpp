class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (auto &x: nums)
            st.insert(x);
        
        int prev = -1e9+7;
        int ans = 0;
        int curr = 0;
        for (auto x: st) {
            if (x - prev == 1) {
                curr++;
            } else {
                curr = 1;
            }
            prev = x;
            ans = max(ans, curr);
        }
        return ans;
    }
};