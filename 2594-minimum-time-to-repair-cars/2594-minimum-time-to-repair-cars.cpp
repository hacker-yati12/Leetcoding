class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long maxel = *max_element(ranks.begin(), ranks.end());
        long long s = 1, e = maxel*cars*cars;
        while(s<=e) {
            long long mid = (s+e)/2;
            long long poss = 0;
            for(auto &x: ranks) {
                poss += sqrt(mid/x);
            }
            if(poss>=cars)
                e = mid-1;
            else 
                s = mid+1;
        } 
        return s;  
    }
};