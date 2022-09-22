class Solution {
public:
    string reverseWords(string s) {
        string ans;
        istringstream temp(s);
        string word;
        
        vector<string> store;
        while(temp>>word)
            store.push_back(word);
        for(auto x:store)
        {
            reverse(x.begin(),x.end());
            ans+=x+" ";
        }
        ans.pop_back();
        return ans;
    }
};