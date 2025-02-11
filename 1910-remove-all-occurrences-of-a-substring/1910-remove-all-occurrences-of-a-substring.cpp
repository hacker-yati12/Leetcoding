class Solution {
    void calcLPS(string &part, int &n, vector<int> &LPS) {
        int i=0, j=1;
        while(j<n) {
            if(part[i]==part[j]) {
                LPS[j] = 1 + i;
                i++;
                j++;
            } else {
                if(i>0)
                    i = LPS[i-1];
                else
                    j++;
            }
        }
    }
    void removeSub(string &s, string &part, vector<int>& LPS) {
        int m = s.size();
        int n = part.size();
        int i = 0;
        int j = 0;
        while(i<m) {
            if(s[i] == part[j]) {
                i++;
                j++;
            }
            if(j == n) {
                s = s.substr(0, i-n) + s.substr(i);
                m = s.size();
                i = max(0, i - 2*n);
                j = 0;
            }
            if(s[i] != part[j]) {
                if(j == 0)
                    i++;
                else
                    j = LPS[j - 1];
            }
        }
    }
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        vector<int> LPS(n, 0);
        calcLPS(part, n, LPS);
        removeSub(s, part, LPS);
        return s;
    }
};