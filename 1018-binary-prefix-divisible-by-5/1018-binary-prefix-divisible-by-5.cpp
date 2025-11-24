class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            curr = (curr << 1) | nums[i];
            ans.push_back(curr%5 == 0);
            curr = curr%5;
        }
        return ans;
    }
};