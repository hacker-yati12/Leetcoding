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
                if(szi > szj)
                    continue;
                bool flag = false;
                for(int k = 0; k <= szj-szi; k++) {
                    string str = words[j].substr(k, szi);
                    if(str == words[i]) {
                        ans.push_back(words[i]);
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        return ans;
    }
};