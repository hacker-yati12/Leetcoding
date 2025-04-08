class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size()-1;
        unordered_set<int> st;
        int i=n;
        for(; i>=0; i--) {
            if(st.find(nums[i])!=st.end())
                break;
            st.insert(nums[i]);
        }
        return (int)ceil((i+1)/3.0);
    }
};