class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool p = (nums[0]&1);
        for(int i=1; i<nums.size(); i++) {
            if((nums[i]&1) == p)
                return false;
            p = !p;
        }
        return true;
    }
};