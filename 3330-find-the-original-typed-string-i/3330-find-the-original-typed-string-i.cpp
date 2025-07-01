class Solution {
public:
    int possibleStringCount(string word) {
        char prev = word[0];
        int ans = 0;
        int ct = 1;
        for(int i=1; i<word.size(); i++) {
            if(word[i] == prev) {
                ct++;
            }
            else {
                ans += ct-1;
                ct=1;
                prev = word[i];
            }
        }
        ans += ct-1;
        return ans+1;
    }
};