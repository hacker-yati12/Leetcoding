class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxv + 1);
        for (int i = 2; i <= maxv; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxv; j += i) {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
        unordered_map<int, vector<int>> mp;
        mp.reserve(n * 2);
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            while (x > 1) {
                int p = spf[x];
                mp[p].push_back(j);
                while (x % p == 0)
                    x /= p;
            }
        }
        vector<int> dist(n, INT_MAX);
        deque<int> q;
        dist[0] = 0;
        q.push_back(0);
        auto isPrime = [&](int x) { return x > 1 && spf[x] == x; };
        while (!q.empty()) {
            int i = q.front();
            q.pop_front();
            int d = dist[i];
            if (i == n - 1)
                return d;
            if (i + 1 < n && dist[i + 1] == INT_MAX) {
                dist[i + 1] = d + 1;
                q.push_back(i + 1);
            }
            if (i - 1 >= 0 && dist[i - 1] == INT_MAX) {
                dist[i - 1] = d + 1;
                q.push_back(i - 1);
            }
            int v = nums[i];
            if (isPrime(v)) {
                auto& lst = mp[v];
                for (int j : lst) {
                    if (j != i && dist[j] == INT_MAX) {
                        dist[j] = d + 1;
                        q.push_back(j);
                    }
                }
                lst.clear();
            }
        }
        return -1;
    }
};