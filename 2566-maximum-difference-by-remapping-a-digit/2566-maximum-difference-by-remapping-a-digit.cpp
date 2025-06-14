class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string mini = "", maxi = "";
        char tar = s[0];
        char maxtar = '9';
        int i=0;
        while(s[i] == '9')
            i++;
        if(i<s.size())
            maxtar = s[i];
        for(auto &x: s) {
            if(tar == maxtar) {
                if(x == tar) {
                    mini += '0';
                    maxi += '9';
                } else {
                    mini += x;
                    maxi += x;
                }
            } else {
                if(x == tar) {
                    mini += '0';
                    maxi += x;
                } else if (x == maxtar) {
                    mini += x;
                    maxi += '9';
                } else {
                    mini += x;
                    maxi += x;
                }
            }
        }
        return stoi(maxi)-stoi(mini);
    }
};