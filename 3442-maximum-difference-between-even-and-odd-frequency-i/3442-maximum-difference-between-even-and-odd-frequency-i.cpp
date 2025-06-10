class Solution {
public:
    int maxDifference(string s) {
        vector<int> fr(26);
        for(auto x: s) {
            fr[x-'a']++;
        }
        int od = 0, ev = INT_MAX;
        for(auto &x: fr) {
            if(x&1)
                od = max(od, x);
            else if(x!=0)
                ev = min(ev, x);
        }
        return od - ev;
    }
};