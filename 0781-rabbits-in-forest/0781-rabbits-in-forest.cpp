class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_set<int> st;
        int ans = 0;
        for(auto &x: answers) {
            if(x == 0) {
                ans++;
                continue;
            }
            st.insert(x);
        }
        for(auto &x: st)
            ans += x+1;
        return ans;
    }
};