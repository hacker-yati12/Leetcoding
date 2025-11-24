class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while(l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            ans += lmax >= rmax ? rmax - height[r--] : lmax - height[l++];
        }
        return ans;
    }
};