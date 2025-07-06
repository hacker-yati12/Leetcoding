class FindSumPairs {
public:
    unordered_map<int, int> mp1,mp2;
    vector<int> num;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num = nums2;
        for(auto &x: nums1) 
            mp1[x]++;
        for(auto &x: nums2) 
            mp2[x]++;
    }
    
    void add(int index, int val) {
        mp2[num[index]]--;
        num[index] += val;
        mp2[num[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &x: mp1) {
            ans += mp2[tot - x.first] * (x.second);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */