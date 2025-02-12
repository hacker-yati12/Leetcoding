class Solution {
    int digitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        for (char c : s)
            sum += (c - '0');
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> mp;
        for(int i=0; i<nums.size(); i++) {
            int dsum = digitSum(nums[i]);
            mp[dsum].insert(nums[i]);
        }
        long long ans = 0;
        for(auto &x: mp) {
            long long curr = 0;
            if(x.second.size()>=2) {
                curr = (*x.second.rbegin()) + (*next(x.second.rbegin()));
                ans = max(ans, curr);
            }
        }
        return ((int)ans==0)?-1: ans;
    }
};