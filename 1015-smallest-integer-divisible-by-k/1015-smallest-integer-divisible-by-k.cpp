class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long n = 1;
        unordered_set<int> st;
        while(n % k != 0) {
            n = 1LL * n * 10 + 1;
            if(st.count(n%k))
                return -1;
            else
                st.insert(n%k);
        }
        return (int)to_string(n).size();
    }
};