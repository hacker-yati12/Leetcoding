class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int curr = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            ans += mp[curr - k];
            mp[curr]++;
        }
        return ans;
    }
};