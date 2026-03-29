class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string str1o = "", str1e = "", str2o = "", str2e = "";
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0)
                str1e += s1[i];
            else 
                str1o += s1[i];
        }
        for (int i = 0; i < s2.size(); i++) {
            if (i % 2 == 0)
                str2e += s2[i];
            else 
                str2o += s2[i];
        } 
        sort(str1e.begin(), str1e.end());
        sort(str1o.begin(), str1o.end());
        sort(str2e.begin(), str2e.end());
        sort(str2o.begin(), str2o.end());
        return str1e == str2e && str1o == str2o;
    }
};