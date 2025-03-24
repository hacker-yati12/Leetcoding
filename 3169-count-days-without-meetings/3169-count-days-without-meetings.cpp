class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> sweep;
        for (auto &x: meetings) {
            sweep[x[0]] += 1;
            sweep[x[1]] -= 1;
        }
        int ans = 0;
        int curr = 0;
        int prev = 0;
        for(auto &x: sweep) {
            if(curr == 0)
                ans += x.first - prev - 1;
            
            curr += x.second;
            prev = x.first;
        }
        ans += days - prev;
        return ans;
    }
};