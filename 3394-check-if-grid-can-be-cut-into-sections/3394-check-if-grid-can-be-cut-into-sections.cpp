class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<int, int> horsweep, vertsweep;
        int ans = 0;
        for(auto &x: rectangles) {
            horsweep[x[0]+1] += 1;
            horsweep[x[2]] -= 1;
        }
        int curr = 0;
        bool check = false;
        for(auto &x: horsweep) {
            if(check && curr == 0)
                ans++;
            check = true;
            curr += x.second;
        }
        if(ans >= 2)
            return true;
        
        ans = 0;
        for(auto &x: rectangles) {
            vertsweep[x[1]+1] += 1;
            vertsweep[x[3]] -= 1;
        }
        curr = 0;
        check = false;
        for(auto &x: vertsweep) {
            if(check && curr == 0)
                ans++;
            check = true;
            curr += x.second;
        }
        if(ans >= 2)
            return true;
        return false;
    }
};