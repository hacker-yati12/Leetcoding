class Solution {
public:
    int maxDiff(int num) {
        string s2=to_string(num);
        string s1 = s2;
        int i=0;
        while(s2[i] == '9')
            i++;
        char c2 = s2[i];
        if(i<s2.size()) {
            replace(s2.begin(), s2.end(), c2, '9');
        }
        int j=0;
        while(s1[j] <= '1')
            j++;
        char c1 = s1[j];
        if(j<s1.size()) {
            if(j!=0)
                replace(s1.begin(), s1.end(), c1, '0');
            else
                replace(s1.begin(), s1.end(), c1, '1');
        }
        return stoi(s2)-stoi(s1);
    }
};