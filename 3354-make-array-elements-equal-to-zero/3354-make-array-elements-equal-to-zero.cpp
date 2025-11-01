class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 2;
        }

        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i - 1] + nums[i];
            suff[n - i - 1] += suff[n - i] + nums[n - i - 1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i])
                continue;

            if(i == 0) {
                if(suff[i + 1] == 0)
                    ans += 2;
                else if (suff[i + 1] == 1)
                    ans++;
            } else if (i == n - 1) {
                if(pref[i - 1] == 0)
                    ans += 2;
                else if (pref[i - 1] == 1)
                    ans++;
            } else {
                if(pref[i - 1] == suff[i + 1])
                    ans += 2;
                if(abs(pref[i - 1] - suff[i + 1]) == 1)
                    ans++;
            }
        }
        return ans;
    }
};