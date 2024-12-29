class Solution {
public:
    long solve(int wordIdx, int targetIdx, vector<vector<int>>& freq, vector<string>& words, string target, 
                                                                vector<vector<long>>& dp) {
        if(targetIdx == target.size()) 
            return dp[wordIdx][targetIdx] = 1;

        if(wordIdx == words[0].size())
            return dp[wordIdx][targetIdx] = 0;
        if((target.size()-targetIdx) > words[0].size()-wordIdx)
            return dp[wordIdx][targetIdx] = 0;
        if(dp[wordIdx][targetIdx] != -1)
            return dp[wordIdx][targetIdx];
        int curr = target[targetIdx] - 'a';
        int fq = freq[wordIdx][curr];

        long take = fq * solve(wordIdx+1, targetIdx+1, freq, words, target, dp);
        long ntake = solve(wordIdx+1, targetIdx, freq, words, target, dp);
        long res = (take+ntake)%(long)(1e9+7);
        return dp[wordIdx][targetIdx] = res;
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        vector<vector<int>> freq(n, vector<int> (26, 0));
        for(auto word: words) {
            for(int i=0; i<n; i++) {
                int charIdx = word[i]-'a';
                freq[i][charIdx]++;
            }
        }
        vector<vector<long>> dp(n+1, vector<long>(m+1, -1));
        return solve(0, 0, freq, words, target, dp);
    }
};