class Solution {
private:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        else
            return false;
    }
public:
    bool halvesAreAlike(string s) {
        int sum1=0,sum2=0;
        for(int i=0;i<s.size()/2;i++)
            if(isVowel(s[i]))
                sum1++;
        for(int i=s.size()/2;i<s.size();i++)
            if(isVowel(s[i]))
                sum2++;
        return sum1==sum2;
    }
};