class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(auto x: s) {
            if(ans.size()>=2 && x==ans.back() && x==ans[ans.size()-2])
                continue;
            ans += x;
        }
        return ans;
    }
};