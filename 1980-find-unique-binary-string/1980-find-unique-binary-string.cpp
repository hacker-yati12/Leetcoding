class Solution {
    bool solve(int n, unordered_set<string>& st, vector<string>& nums, string &ans) {
        if(ans.size()==n)
            return st.find(ans)==st.end();
        for(char i='0'; i<='1'; i++) {
            ans.push_back(i);
            if(solve(n, st, nums, ans))
                return true;
            ans.pop_back();
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> st;
        for(auto &x: nums)
            st.insert(x);        
        string ans = "";
        solve(n, st, nums, ans);
        return ans;
    }
};