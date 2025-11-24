class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st;
        for (auto &x: nums)
            st.insert(x);

        for (auto x: st) {
            if (!(st.count(x - 1))) {
                int curr = 1;
                while (st.count(x + 1)) {
                    x = x + 1;
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};