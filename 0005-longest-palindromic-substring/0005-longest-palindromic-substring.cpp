class Solution {
    string check(int i, int j, string s) {
        while(i>=0 && j<s.size() && s[i]==s[j]) {
            i--;
            j++;
        }
        ++i;
        --j;
        return s.substr(i, j-i+1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        string odd="", even="";
        for(int i = 0; i < n-1; i++) {
            string o = check(i, i, s);
            odd = (o.size() > odd.size())? o : odd;
            string e = check(i, i+1, s);
            even = (e.size() > even.size())? e : even;
        }
        return (odd.size() > even.size())?odd : even;
    }
};