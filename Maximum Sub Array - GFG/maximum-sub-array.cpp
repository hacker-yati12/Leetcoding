//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> res, curr;
	    int len = 0, start = 0, sum = INT_MIN, curr_sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        start = i;
	        if(a[i] < 0) 
	            continue;
	        while(i < n && a[i] >= 0)
	        {
	            curr_sum += a[i];
	            curr.push_back(a[i]);
	            i++;
	        }
	        if(curr_sum > sum || (curr_sum == sum && i - start > len)) 
	        {
	            sum = curr_sum;
	            len = i - start;
	            res = curr;
	        }
	        curr_sum = 0;
	        curr.clear();
	    }
	    if(res.size()) 
	        return res;
	    return {-1};
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends