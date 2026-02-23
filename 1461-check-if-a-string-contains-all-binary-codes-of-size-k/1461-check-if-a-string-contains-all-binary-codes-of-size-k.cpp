class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string str = "";
        int i = 0;
        while(i < k && i < s.size())
            str += s[i++];
        st.insert(str);
        for(int i = 1; i + k <= s.size(); i++) {
            str.erase(0, 1);
            str += s[i+k-1];
            st.insert(str);
        }
        for(auto x: st)
            cout<<x<<" ";
        return st.size() == pow(2, k);
    }
};