class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int j=0; j<words.size(); j++) {
            int n = words[j].size();
            for(int i=0; i<(n+1)/2; i++) {
                if(words[j][i]==x || words[j][n-i-1]==x) {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};