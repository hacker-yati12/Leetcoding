class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0, num2 = 0, ct1 = 0, ct2 = 0;

        for (int x : nums) {
            if (x == num1) 
                ct1++;
            else if (x == num2) 
                ct2++;
            else if (ct1 == 0) 
                num1 = x, ct1 = 1;
            else if (ct2 == 0) 
                num2 = x, ct2 = 1;
            else 
                ct1--, ct2--;
        }

        ct1 = ct2 = 0;
        for (int x : nums) {
            if (x == num1) 
                ct1++;
            else if (x == num2) 
                ct2++;
        }

        vector<int> ans;
        if (ct1 > n/3) 
            ans.push_back(num1);
        if (ct2 > n/3) 
            ans.push_back(num2);
        return ans;
    }
};
