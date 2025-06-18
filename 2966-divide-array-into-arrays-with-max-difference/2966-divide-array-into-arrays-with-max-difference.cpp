class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int sz = 3;
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i=0; i<nums.size(); i++) {
            if(i%sz == 0 && i!=0) {
                last = nums[i];
                ans.push_back(curr);
                curr.clear();
            }
            if(abs(nums[i] - last) > k)
                return {};
            curr.push_back(nums[i]);
        }
        ans.push_back(curr);
        return ans;
    }
};