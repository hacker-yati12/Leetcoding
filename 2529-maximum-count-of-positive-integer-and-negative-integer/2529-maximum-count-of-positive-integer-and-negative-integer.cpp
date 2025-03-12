class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto t1 = upper_bound(nums.begin(), nums.end(), 0);
        auto t2 = lower_bound(nums.begin(), nums.end(), 0);
        int pos = nums.end() - t1;
        int neg = t2 - nums.begin();
        return max(pos, neg);
    }
};