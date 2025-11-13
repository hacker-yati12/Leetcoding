class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ct1 = 0;
        for(int i = 0; i < s.size();) {
            if(s[i] == '1') {
                ct1++;
                i++;
                continue;
            } else {
                while(s[i] == '0') {
                    i++;
                }
                ans += ct1;
            }
        }
        return ans;
    }
};