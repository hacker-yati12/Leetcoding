class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()==2)
            return 2;

        int ans = 1;
        int od = 0, ev = 0;
        bool odd = (nums[0]&1)?true:false;      
        if(odd)
            od++;
        else
            ev++;
        for(int i=1;i<nums.size(); i++) {
            if(nums[i]&1 && !odd) {
                odd = !odd;
                ans++;
            }
            else if(!(nums[i]&1) && odd) {
                odd = !odd;
                ans++;
            }
            if(nums[i]&1)
                od++;
            else
                ev++;
        }
        return max({ev, od, ans});
    }
};