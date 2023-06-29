//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>

int solve(int n)
{
    if(n==1)
        return 1;
    int ans = n;
    for(int i=2;i*i<=n;i++)
    {
        ans=min(ans, 1+solve(n-(i*i)));
    }
    return ans;
}

int solveMem(int n, vector<int>& dp)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int ans = n;
    
    if(dp[n]!=-1)
        return dp[n];
        
    for(int i=2;i*i<=n;i++)
    {
        ans=min(ans, 1+solveMem(n-(i*i), dp));
    }
    
    dp[n]=ans;
    return dp[n];
}

int solveTab(int n)
{
    vector<int> dp(n+1, INT_MAX);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j*j<=n;j++)
        {
            if(i-(j*j)>=0)
                dp[i]=min(dp[i], 1+dp[i-(j*j)]);
        }
    }
    return dp[n];
}

class Solution{
	public:
	int MinSquares(int n)
	{
	    // Code here
	    return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends