class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxfreq(26);
        vector<int> cfreq(26);
        for(auto word: words2) {
            for(auto x: word) {
                cfreq[x-'a']++;
            }

            for(int i=0; i<26; i++) {
                maxfreq[i] = max(maxfreq[i], cfreq[i]);
            }
            fill(cfreq.begin(), cfreq.end(), 0);
        }
        
        vector<string> ans;
        for(auto word: words1) {            
            for(auto x: word) {
                cfreq[x-'a']++;
            }

            for(int i=0; i<26; i++) {
                if(cfreq[i]>0) {
                    cout<<char('a'+i)<<" "<<cfreq[i]<<"\n";
                }
            }

            bool flag = true;
            for(int i=0; i<26; i++) {
                if(maxfreq[i] > cfreq[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
            fill(cfreq.begin(), cfreq.end(), 0);
        }
        return ans;
    }
};