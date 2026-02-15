class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size()-1,n=b.size()-1;
        int temp=0;
        string res="";
        while(m>=0 || n>=0 || temp==1)
        {
            temp+=((m>=0)?a[m]-'0':0);
            temp+=((n>=0)?b[n]-'0':0);
            res=char(temp%2+'0')+res;
            temp/=2;
            m--;
            n--;
        }
        return res;
    }
};