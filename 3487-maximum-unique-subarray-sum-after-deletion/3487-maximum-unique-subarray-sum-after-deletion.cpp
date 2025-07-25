class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        auto itr = upper_bound(nums.begin(), nums.end(), 0);
        int sum = 0;
        while(itr != nums.end()) {
            if(*itr > 0)
                sum += *itr;
            itr++;
        }
        if(sum == 0)
            sum = nums.back();
        return sum;
    }
};