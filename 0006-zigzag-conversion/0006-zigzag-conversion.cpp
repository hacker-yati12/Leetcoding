class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int i = 0;
        bool dir = false;
        vector<string> vec(numRows);
        for(auto &x: s) {
            vec[i].push_back(x);
            if(i == numRows-1 || i == 0)
                dir = !dir;
            
            if(dir)
                i++;
            else
                i--;
        }
        string ans = "";
        for(auto &x: vec) {
            ans += x;
        }
        return ans;
    }
};