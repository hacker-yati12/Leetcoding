class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            int szi = words[i].size();
            for(int j = 0; j < n; j++) {
                if(j == i)
                    continue;
                int szj = words[j].size();
                if(szj > szi)
                    continue;
                for(int k = 0; k <= szi-szj; k++) {
                    string str = words[i].substr(k, szj);
                    if(str == words[j]) {
                        ans.push_back(words[j]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};