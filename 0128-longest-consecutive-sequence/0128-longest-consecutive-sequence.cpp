class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto &x: nums)
            st.insert(x);
        int ans = 0;
        for (auto x: st) {
            if (!st.count(x - 1)) {
                int curr = 1;
                while (st.count(x + 1)) {
                    curr++;
                    x++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};