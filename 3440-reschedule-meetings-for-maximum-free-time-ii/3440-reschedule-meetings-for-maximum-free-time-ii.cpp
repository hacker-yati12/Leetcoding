class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& ed) {
        int ans = 0;
        vector<int> space;
        space.push_back(st[0]);
        for(int i=1; i<st.size(); i++) 
            space.push_back(st[i]-ed[i-1]);
        space.push_back(eventTime-ed.back());
        int sz = space.size();
        vector<int> lm(sz), rm(sz);
        lm[0] = space[0];
        for(int i=1;i<sz; i++)
            lm[i] = max(lm[i-1], space[i]);
        rm[sz-1] = space[sz-1];
        for(int i=sz-2; i>=0; i--)
            rm[i] = max(rm[i+1], space[i]);
        for(int i=0; i<st.size(); i++) {
            int curr = 0;
            if(i-1>=0)
                curr = max(curr, lm[i-1]);
            if(i+2<rm.size())
                curr = max(curr, rm[i+2]);

            if(curr>=ed[i]-st[i]) {
                ans = max(ans, space[i]+space[i+1]+(ed[i]-st[i]));
            } else {
                ans = max(ans, space[i]+space[i+1]);
            }
        }
        return ans;
    }
};