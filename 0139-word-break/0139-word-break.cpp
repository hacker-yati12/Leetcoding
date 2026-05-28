class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (auto wd: wordDict) {
                if (wd.size() - 1 > i)
                    continue;
                
                if (wd.size() - 1 == i || dp[i - wd.size()]) {
                    if (s.substr(i - wd.size() + 1, wd.size()) == wd) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};