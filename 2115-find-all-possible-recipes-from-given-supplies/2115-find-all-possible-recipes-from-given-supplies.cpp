class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> avl;
        for(auto &x: supplies)
            avl.insert(x);
        unordered_set<string> st;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(avl.find(recipes[j]) == avl.end()) {
                    bool found = true;
                    for(auto &x: ingredients[j]) {
                        if(avl.find(x) == avl.end())
                            found = false;
                    }
                    if(found) {
                        supplies.push_back(recipes[j]);
                        st.insert(recipes[j]);
                        avl.insert(recipes[j]);
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