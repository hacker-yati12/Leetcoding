class Solution {
    vector<vector<string>> ans;
    bool isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void solve(string s, vector<string>& curr, int idx) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, curr, i + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s, curr, 0);
        return ans;
    }
};