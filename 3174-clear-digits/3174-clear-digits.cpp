class Solution {
public:
    string clearDigits(string s) {
        int dgc = 0, chc = 0;
        string ans = "";
        for(int i = s.size()-1; i>=0; i--) {
            if(s[i]>='a' && s[i]<='z')
                chc++;
            else
                dgc++;
            if(chc>dgc && (s[i]>='a' && s[i]<='z')) {
                ans = s[i] + ans;
                chc--;
            }
        }
        return ans;
    }
};