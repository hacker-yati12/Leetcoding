class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string pref = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int k = min(pref.size(),strs[i].size());
            string temp = "";
            for(int j=0;j<k;j++)
            {
                if(pref[j]==strs[i][j])
                    temp+=pref[j];
                else
                    break;
            }
            pref = temp;
        }
        return pref;
    }
};