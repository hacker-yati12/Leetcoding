//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int solve(int n, int a[], int prev, int curr, vector<vector<int>>& dp)
    {
        if(curr == n)
            return 0;
        if(dp[prev+1][curr]!=-1)
            return dp[prev+1][curr];
            
        int include = 0;
        if(prev==-1 || a[prev] < a[curr])
        {
            include = 1 + solve(n, a, curr, curr+1, dp);
        }
        int exclude = solve(n, a, prev, curr+1, dp);
        return dp[prev+1][curr] = max(include, exclude);
    }
    
    int solveTab(int n, int a[])
    {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                int include = 0;
                if(prev==-1 || a[curr] > a[prev])
                {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    int solveTab2(int n, int a[])
    {
        if(n==0)
            return 0;
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector<int>> dp(n, vector<int> (n+1, -1));
    //   return solve(n, a, -1, 0, dp);
    return solveTab2(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends