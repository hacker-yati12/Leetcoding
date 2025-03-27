class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> left, right;
        for(int &x: nums) 
            right[x]++;
        for(int i=0; i<n; i++) {
            left[nums[i]]++;
            right[nums[i]]--;
            if(left[nums[i]] >= ((i+1)/2)+1 && right[nums[i]] >= (n-i+1)/2)
                return i;
        }
        return -1;
    }
};