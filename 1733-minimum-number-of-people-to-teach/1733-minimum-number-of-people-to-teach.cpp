class Solution {
    int solve(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int ct = INT_MAX;
    int users = languages.size();

    // Convert each user's language list into a set for faster lookup
    vector<unordered_set<int>> langs(users);
    for (int i = 0; i < users; i++) {
        for (int l : languages[i]) langs[i].insert(l);
    }

    for (int lang = 1; lang <= n; lang++) {
        int curr = 0;
        vector<bool> vis(users, false);

        for (auto &x : friendships) {
            int u = x[0] - 1, v = x[1] - 1;

            // Skip if u and v already share a language
            bool share = false;
            for (int l : langs[u]) {
                if (langs[v].count(l)) { share = true; break; }
            }
            if (share) continue;

            if (!langs[u].count(lang) && !vis[u]) {
                curr++;
                vis[u] = true;
            }
            if (!langs[v].count(lang) && !vis[v]) {
                curr++;
                vis[v] = true;
            }
        }
        ct = min(ct, curr);
    }
    return ct;
}
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        return solve(n, languages, friendships);
    }
};