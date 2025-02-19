class Solution {
    bool solve(int n, string &ans, int &ct, int k) {
        if(ans.size() == n) {
            ++ct;  
            return ct == k;  
        }
        for(char i = 'a'; i <= 'c'; i++) {
            if(ans.empty() || ans.back() != i) {  
                ans.push_back(i);
                if(solve(n, ans, ct, k)) 
                    return true;
                ans.pop_back();  
            }
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int ct = 0;
        if(solve(n, ans, ct, k)) 
            return ans;
        return "";
    }
};
