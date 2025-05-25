class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        int same = 0;
        string rev = "";
        for(string &x: words) {
            rev = string("") + x[1] + x[0];
            if(mp[rev]>0) {
                ans += 4;
                mp[rev]--;
                if(rev == x && mp[rev]==0)  
                    same--;              
                continue;
            }
            mp[x]++;
            if(rev == x)
                same++;
        }
        if(same > 0)
            ans += 2;
        return ans;
    }
};