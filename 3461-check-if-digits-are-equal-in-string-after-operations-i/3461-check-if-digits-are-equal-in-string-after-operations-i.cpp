class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string s1 = "";
            for(int i = 0; i < s.size() - 1; i++) {
                int sum = ((s[i] - '0') + (s[i+1] - '0')) % 10;
                s1.push_back('0' + sum);
            }
            s = s1;
        }
        return s[0] == s[1];
    }
};