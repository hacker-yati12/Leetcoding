class Solution {
public:
    string invert(string str){
        for(auto &c:str)
            c = (c=='0')?'1':'0';
        return str;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;i++){
            string str = invert(s);
            reverse(str.begin(),str.end());
            s = s + '1' + str;
        }
        return s[k-1];
    }
};