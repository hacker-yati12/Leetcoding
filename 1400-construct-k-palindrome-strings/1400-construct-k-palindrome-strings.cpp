class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        vector<int> freq(26, 0);
        for(auto &x: s) {
            freq[x-'a']++;
        }
        int count = 0;
        for(int i=0; i<26; i++) {
            if(freq[i]&1)
                count++;
        }
        return count<=k;
    }
};