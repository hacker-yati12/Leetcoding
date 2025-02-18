class Solution {
    void solve(string pattern, vector<bool>& used, string &ans, int idx) {
        if(pattern[idx-1] == 'I') {
            int j = ans[idx-1]-'0';
            for(; j<=9; j++) {
                if(used[j])
                    continue;
                ans.push_back('0'+j);
                used[j] = true;
                solve(pattern, used, ans, idx+1);
                if(ans.size() == pattern.size()+1)
                    break;
                used[j] = false;
                ans.pop_back();
            }
        } else {
            int j = ans[idx-1]-'0';
            for(; j>=1; j--) {
                if(used[j])
                    continue;
                ans.push_back('0'+j);
                used[j] = true;
                solve(pattern, used, ans, idx+1);
                if(ans.size() == pattern.size()+1)
                    break;
                used[j] = false;
                ans.pop_back();
            }
        }
        return;
    }
public:
    string smallestNumber(string pattern) {
        string ans = "";
        vector<bool> used(10, false);
        for(int i=1; i<=9; i++) {
            ans.push_back('0'+i);
            used[i] = true;
            solve(pattern, used, ans, 1);
            if(ans.size() == pattern.size()+1)
                break;
            used[i] = false;
            ans.pop_back();
        }
        return ans;
    }
};