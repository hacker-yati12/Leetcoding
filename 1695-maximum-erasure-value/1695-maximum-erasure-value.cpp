class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        int i=0, j=0;
        int curr = 0;
        while(i<=j && j != nums.size()) {
            if(mp[nums[j]] != 0) {
                ans = max(ans, curr);
                while(mp[nums[j]] != 0) {
                    curr -= nums[i];
                    mp[nums[i]]--;
                    i++;
                }
            }
            curr += nums[j];
            mp[nums[j]]++;
            j++;
        }
        ans = max(ans, curr);
        return ans;
    }
};