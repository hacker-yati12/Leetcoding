class Solution {
public:
    char kthCharacter(int k) {
        string s1="a";
        while(s1.size()<=k) {
            string s2=s1;
            for(auto &x: s1) {
                s2 += x+1;
            }
            s1=s2;
        }
        return s1[k-1];
    }
};