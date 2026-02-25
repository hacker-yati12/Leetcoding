class Solution {
private:
    struct Comp {
        bool operator()(const int &a, const int &b) const {
            int pa = __builtin_popcount(a);
            int pb = __builtin_popcount(b);

            if (pa == pb)
                return a < b;
            return pa < pb;
        }
    };

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), Comp());
        return arr;
    }
};