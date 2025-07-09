class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& ed) {
        int ans = 0;
        vector<int> space;
        space.push_back(st[0]);
        for(int i=1; i<st.size(); i++) {
            space.push_back(st[i]-ed[i-1]);
        }
        space.push_back(eventTime-ed.back());
        // for(auto &x: space)
        //     cout<<x<<" ";
        int wd = k+1;
        int curr = 0;
        int i =0, j =0;
        while(j<space.size() && j-i<wd) {
            curr += space[j++];
        }
        ans = max(ans, curr);
        while(i<space.size() && j<space.size()) {
            curr -= space[i++];
            curr += space[j++];
            ans = max(ans, curr);            
        }
        return ans;
    }
};