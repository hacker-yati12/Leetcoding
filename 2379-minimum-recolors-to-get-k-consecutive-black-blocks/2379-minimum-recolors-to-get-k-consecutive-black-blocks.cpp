class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ct = 0;
        int ans = INT_MAX;
        int s=0, e=0;
        while(e-s<=k-1) {
            if(blocks[e]=='W')
                ct++;
            ++e;
        }
        ans = min(ans, ct);
        while(e<blocks.size()) {
            if(blocks[s++] == 'W')
                ct--;
            if(blocks[e++] == 'W')
                ct++;
            ans = min(ans, ct);
        }
        return ans;
    }
};