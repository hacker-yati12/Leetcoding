class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        int ans = 0;
        for (auto &x: nums) {
            while (!st.empty() && st.back() > x) 
                st.pop_back();
            if (x == 0)
                continue;
            if (st.empty() || st.back() < x) {
                ans++;
                st.push_back(x);
            }
        }
        return ans;
    }
};