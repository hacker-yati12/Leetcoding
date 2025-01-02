class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> present;
        present.push_back(0);
        for(auto x: words) {
            if(isVowel(x.front()) && isVowel(x.back()))
                present.push_back(1);
            else
                present.push_back(0);
        }
        for(int i=1; i<present.size(); i++) {
            present[i] = present[i]+present[i-1];
        }
        vector<int> ans;
        for(auto x: queries) {
            ans.push_back(present[x[1]+1] - present[x[0]]);
        }
        return ans;
    }
};