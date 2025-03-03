class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int ans = 0;
        for(int k=2; k<n; k++) {
            int i=0, j=k-1;
            while(i<j) {
                if(arr[i]+arr[j]<arr[k])
                    i++;
                else if(arr[i]+arr[j]>arr[k])
                    j--;
                else {
                    dp[j][k] = dp[i][j] + 1;
                    ans = max(ans, dp[j][k]);
                    i++, j--;
                }
            }
        }
        return (ans==0)?0:ans+2;
    }
};