class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int> mp;
        for(auto &x: supplies)
            mp[x] = 1;
        unordered_set<string> st;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!mp[recipes[j]]) {
                    bool found = true;
                    for(auto &x: ingredients[j]) {
                        if(!mp[x])
                            found = false;
                    }
                    if(found) {
                        supplies.push_back(recipes[j]);
                        st.insert(recipes[j]);
                        mp[recipes[j]] = 1;
                    }
                }
                else 
                    st.insert(recipes[j]);
            }
            if(st.size() == recipes.size())
                break;
        }
        vector<string> ans;
        for(auto &x: st)
            ans.push_back(x);
        return ans;
    }
};