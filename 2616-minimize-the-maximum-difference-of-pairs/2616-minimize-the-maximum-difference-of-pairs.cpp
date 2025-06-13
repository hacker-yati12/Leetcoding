class Solution {
    bool possible(vector<int>& nums, int maxD, int p) {
        int ct = 0;
        for(int i=0; i<nums.size()-1; i++) {
            if(abs(nums[i]-nums[i+1]) <= maxD) {
                ct++;
                ++i;
            }
        }
        return ct>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back();
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(possible(nums, mid, p)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};