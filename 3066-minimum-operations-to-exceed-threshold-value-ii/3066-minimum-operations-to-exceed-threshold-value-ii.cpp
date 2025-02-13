class Solution {
public:
    long long int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> q;
        for(auto &x: nums) 
            q.push(x);
        long long int ops = 0;
        while(q.size()>=2 && q.top()<k) {
            ops++;
            long long int n1 = q.top();
            q.pop();
            long long int n2 = q.top();
            q.pop();
            q.push(n1*2+n2);
        }
        return ops;
    }
};