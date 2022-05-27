class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber)
        {
            int rem=columnNumber%26;
            if(rem==0)
                rem=26;
            char c=64+rem;
            res=c+res;
            columnNumber=(columnNumber-rem)/26;
        }
        return res;
    }
};