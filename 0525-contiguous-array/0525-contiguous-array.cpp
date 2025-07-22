class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            if(i!=0)
                pref[i] += pref[i-1];
            if(nums[i]==1) 
               pref[i] += 1; 
            else
                pref[i] -= 1;
            mp[pref[i]].push_back(i);
        }
        // for(auto &X: pref)
        //     cout<<X<<" ";
        int ans = 0;
        for(auto &x: mp) {
            ans = max(ans, x.second.back() - x.second[0]);
        }
        if(mp[0].size())
            ans = max(ans, mp[0].back()+1);
        return ans;
    }
};