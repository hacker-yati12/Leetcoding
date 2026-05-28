class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int comp;
        for(int i = 0; i < nums.size(); i++) {
            comp = target - nums[i];
            if(mp.find(comp) != mp.end())
                return {i, mp[comp]};
            mp[nums[i]] = i;
        }
        return {};
    }
};