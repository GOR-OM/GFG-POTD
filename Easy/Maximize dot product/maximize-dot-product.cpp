//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	 int  solve(int n, int m, int a[], int b[],int i, int j, int count, vector<vector<int>> &dp)
    {
        int ans = INT_MIN; 
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if((n - m) > count)
        {
            ans = max(ans, solve(n,m,a,b,i+1,j,count+1,dp));
        }
        
        ans = max(ans,(a[i] * b[j]) + solve(n,m,a,b,i+1,j+1,count,dp));
        return dp[i][j] = ans;
    }
    int maxDotProduct(int n, int m, int a[], int b[]) 
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n,m,a,b,0,0,0,dp);
       // return ans;
        // Your code goes here
    }  
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends