class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        if (n <= 1)
            return n;
        int ans = 0, curr = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (mp.count(s[i])) {
                last = max(last, mp[s[i]]);
                curr = i - last;
            } else {
                curr++;
            }
            ans = max(ans, curr);
            mp[s[i]] = i;
        }
        return max(ans, curr);
    }
};