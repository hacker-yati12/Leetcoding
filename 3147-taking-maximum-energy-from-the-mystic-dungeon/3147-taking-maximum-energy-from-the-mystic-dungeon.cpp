class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -1e4;
        int n = energy.size();
        for(int i = 1; i <= k; i++) {
            int curr = -1e4;
            for(int j = i - 1; j < n; j += k) {
                curr = max(energy[j], curr + energy[j]);
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};