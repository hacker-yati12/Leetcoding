class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size();
        int n = skill.size();
        vector<vector<long long>> table(m, vector<long long> (n+1, 0));
        for(int i = 1; i <= n; i++)
            table[0][i] = table[0][i-1] + skill[i - 1] * mana[0];

        for(int i = 1; i < m; i++) {
            table[i][0] = table[i-1][1];
            for(int j = 1; j < n; j++) {
                table[i][j] = max(table[i-1][j+1], table[i][j - 1] + skill[j - 1] * mana[i]);
            }
            table[i][n] = table[i][n - 1] + skill[n - 1] * mana[i];

            for(int j = n - 1; j >= 0; j--) {
                table[i][j] = table[i][j+1] - (skill[j] * mana[i]);
            }
            table[i][n] = table[i][n - 1] + skill[n - 1] * mana[i];
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j <= n; j++) {
                cout<<table[i][j]<<" ";
            }
            cout<<"\n";
        }
        return table[m - 1][n];
    }
};