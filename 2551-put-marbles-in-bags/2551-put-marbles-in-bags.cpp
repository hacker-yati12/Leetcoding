class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long n = weights.size();
        vector<long long> ps;
        for(int i=1; i<n; i++)
            ps.push_back((long long)weights[i-1]+(long long)weights[i]);
        sort(ps.begin(), ps.end());
        long long mxs=0, mns=0; 
        for(int i=0; i<k-1; i++) {
            mns += ps[i];
            mxs += ps[n-2-i];
        }
        return mxs-mns;
    }
};