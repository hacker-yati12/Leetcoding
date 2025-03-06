class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xr1=0, xr2=0;
        for(int i=1; i<=n*n; i++)
            xr1^=i;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                xr2^=grid[i][j];
            }
        }
        int xr = xr1^xr2;
        int ct=0;
        while(!(xr&1)) {
            ct++;
            xr=xr>>1;
        }
        int mask = 1<<ct;
        int left = 0, right = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]&mask)
                    left ^= grid[i][j];
                else
                    right ^= grid[i][j];
            }
        }
        for(int i=1; i<=n*n; i++) {
            if(i & mask)
                    left ^= i;
                else
                    right ^= i;
        }
        bool pres = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==left)
                    pres = true;
            }
        }
        if(pres) 
            return {left, right};
        else
            return {right, left};
    }
};