class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<101> st;
        for(auto &x: nums) {
            if(x < k)
                return -1;
            if(x == k)
                continue;
            st.set(x);
        }
        return st.count();
    }
};