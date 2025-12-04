class Solution {
public:
    int countCollisions(string directions) {
        int i = 0;
        int n = directions.size();
        while (i < n && directions[i] == 'L')
            i++;
        int j = directions.size() - 1;
        while (j >= 0 && directions[j] == 'R')
            j--;
        int ans = 0;
        int ctr = 0;
        while (i <= j) {
            if (directions[i] == 'R') {
                ctr++;
            } else if (directions[i] == 'L') {
                ans += ctr + 1;
                ctr = 0;
            } else {
                ans += ctr;
                ctr = 0;
            }
            i++;
        }
        return ans;
    }
};