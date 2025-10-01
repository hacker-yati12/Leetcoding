#define ll long long

struct DSU {
    vector<int> par, rnk;

    DSU(int n) {
        par.assign(n+1, 0);
        rnk.assign(n+1, 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find_set(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find_set(par[x]);
    }

    bool union_set(int a, int b) {
        int p1 = find_set(a), p2 = find_set(b);
        if (p1 == p2)
            return 0;
        if (rnk[p1] > rnk[p2]) {
            par[p2] = p1;
        } else {
            par[p1] = p2;
            rnk[p2] += rnk[p1];
        }
        return 1;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        DSU dsu(n);
        for(auto v: swaps) {
            dsu.union_set(v[0], v[1]);
        }
        vector<vector<int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[dsu.find_set(i)].push_back(i);
        }
        ll ans = 0;
        for (auto v: vec) {
            if (v.empty())
                continue;
            int c = 0;
            vector<int> val;
            for (auto i: v) {
                val.push_back(nums[i]);
                if (i % 2)
                    c++;
            }
            sort(val.begin(), val.end());
            for (int i = 0; i < val.size(); i++) {
                if (i < c)
                    ans -= val[i];
                else
                    ans += val[i];
            }
        }
        return ans;
    }
};