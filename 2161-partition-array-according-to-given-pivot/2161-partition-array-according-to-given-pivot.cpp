class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, INT_MAX);
        int i=0, j=n-1; 
        for(int k = 0; k<n; k++) {
            if(nums[k]<pivot)
                ans[i++] = nums[k];
            if(nums[n-k-1]>pivot)
                ans[j--]=nums[n-k-1];
        }
        while(i<n && ans[i]==INT_MAX)
            ans[i++]=pivot;
        return ans;
    }
};