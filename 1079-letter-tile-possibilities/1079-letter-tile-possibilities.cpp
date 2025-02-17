class Solution {
    void solve(string tiles, unordered_set<string>& st, vector<bool>& used, string curr, int idx) {
        if(idx == tiles.size())
            return;
        for(int i=0; i<tiles.size(); i++) {
            if(used[i])
                continue;
            used[i] = true;
            curr += tiles[i];
            st.insert(curr);
            solve(tiles, st, used, curr, idx+1);
            used[i] = false;
            curr.pop_back();
            // solve(tiles, st, used, curr, idx+1);
        }
        return;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        vector<bool> used(tiles.size(), false);
        solve(tiles, st, used, "", 0);
        return st.size();
    }
};