class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<long double> pq(nums.begin(), nums.end());
        long double sum = accumulate(nums.begin(), nums.end(), 0.0L);
        long double tar = sum/2.0;
        int ops = 0;
        while(sum>tar) {
            long double n = pq.top();
            pq.pop();
            sum -= n/2.0;
            pq.push(n/2.0);
            ops++;
        }
        return ops;
    }
};