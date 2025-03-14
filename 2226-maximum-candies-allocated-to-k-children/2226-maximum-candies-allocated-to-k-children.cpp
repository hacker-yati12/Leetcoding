class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum<k)
            return 0;
        long long ans = 0;
        long long s = 1, e = sum/k;
        while(s<=e) {
            long long mid = s + (e-s)/2;
            long long count = 0;
            for(auto &x: candies)
                count += x/mid;
            if(count<k)
                e = mid-1;
            else
                s = mid + 1;
        }
        return s-1;
    }
};