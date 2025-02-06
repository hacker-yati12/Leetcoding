class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int prod = nums[i]*nums[j];
                if(mp.find(prod) != mp.end()) {
                    ans += 8*mp[prod];
                }
                mp[prod]++;
            }
        }
        return ans;
    }
};