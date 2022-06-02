class Solution {
public:
    bool palindrome(string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;    
    } 

bool validPalindrome(string s) {
    int n=s.length(); 
    
    int st=0,e=n-1; 
    
    while(st < e) 
    {
        if(s[st] == s[e]) 
        {
            st++; 
            e--; 
        } 
        else 
        {
            return palindrome(s, st+1, e) || palindrome(s, st, e-1); 
        }
    } 
    return true; 
    }
};