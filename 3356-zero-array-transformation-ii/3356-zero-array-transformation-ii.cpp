class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sweep(n+1, 0);
        int k=0, curr = 0;
        int i = 0;
        while(i<n) {
            if(k==queries.size())
                return -1;
            if(nums[i]-curr<=0) {
                i++;
                curr += sweep[i];
                continue;
            }
            if(queries[k][1]<i) {
                k++;
                continue;
            }
            if(queries[k][0]<=i && queries[k][1]>=i)
                curr += queries[k][2];
            sweep[queries[k][0]] += queries[k][2];
            sweep[queries[k][1]+1] -= queries[k][2];
            k++;
        }
        return k;
    }
};