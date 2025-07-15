class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)
            return false;
        bool vowel = false, cons = false;
        char ch;
        for(auto x: word) {
            if (!isalnum(x)) 
                return false;
            else if (isalpha(x)){
                ch = tolower(x);
                if(ch=='a' || ch == 'e' || ch=='i' || ch=='o' || ch=='u')
                    vowel = true;
                else
                    cons = true;
            }
        }
        return (vowel&&cons);
    }
};