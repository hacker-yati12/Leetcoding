class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++)
        {
            int j=0;
            for(;j<needle.size() && i+j<haystack.size();j++)
            {
                if(needle[j]==haystack[i+j])
                    continue;
                else 
                    break;
            }
            if(j==needle.size())
                return i;
        }
        return -1;
    }
};