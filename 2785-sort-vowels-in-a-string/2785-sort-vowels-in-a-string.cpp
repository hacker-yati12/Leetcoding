class Solution {
public:
    string sortVowels(string s) {
        string str = "";
        for(auto x: s) {
            if(x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' 
                || x=='u' || x=='U') {
                    str.push_back(x);
                }
        }
        sort(str.begin(),str.end());
        int i = 0;
        for(auto &x: s) {
            if(x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' 
                || x=='u' || x=='U') {
                    x=str[i++];
                }
        }
        return s;
    }
};