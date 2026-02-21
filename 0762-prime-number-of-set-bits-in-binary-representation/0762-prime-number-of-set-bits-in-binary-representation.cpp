class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        unordered_set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for(int i = left; i <= right; i++) {
            int ct = __builtin_popcount(i);
            if (st.count(ct))
                ans++;
        }
        return ans;
    }
};