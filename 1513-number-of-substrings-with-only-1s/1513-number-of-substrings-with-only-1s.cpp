class Solution {
public:
    int numSub(string s) {
        int ans = 0;
        int mod = 1e9 + 7;
        int n = s.size();
        int i = 0;
        while (i < n && s[i] != '1') i++;
        int j = i;
        while(j < s.size()) {
            if (s[j] == '1')
                j++;
            else {
                int ct = j - i;
                ans += ((1LL * ct * (ct + 1))/2) % mod;
                while (j < n && s[j] != '1') j++;
                i = j;
            }
        }
        int ct = j - i;
        ans += ((1LL * ct * (ct + 1))/2) % mod;
        return ans;
    }
};