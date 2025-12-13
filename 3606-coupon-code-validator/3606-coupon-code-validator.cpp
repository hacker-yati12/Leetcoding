class Solution {
private:
    bool valid(int idx, vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        if(code[idx].empty())
            return false;
        for(auto x: code[idx]) {
            if(!(isalnum(x) || x =='_'))
                return false;
        }
        if(!(businessLine[idx] == "electronics" || businessLine[idx] == "grocery" || businessLine[idx] == "pharmacy" || businessLine[idx] == "restaurant"))
            return false;
        if(isActive[idx] == false)
            return false;
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            vec[i] = i;
        sort(vec.begin(), vec.end(), [&](int a, int b) {
            if (businessLine[a] == businessLine[b])
                return code[a] < code[b];
            return businessLine[a] < businessLine[b];
        });
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (valid(vec[i], code, businessLine, isActive))
                ans.push_back(code[vec[i]]);
        }
        return ans;
    }
};