class Solution {
    string expand(string s, int i, int j) {
        int l = i, r = j;
        while(l>=0 && r<s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r - l - 1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expand(s, i, i);
            if (odd.size() > ans.size())
                ans = odd;
        }
        for (int i = 0; i < s.size(); i++) {
            string even = expand(s, i, i + 1);
            if (even.size() > ans.size())
                ans = even;
        }
        return ans;
    }
};