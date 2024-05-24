//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int mod=1e9+7;
  int solve(int n,vector<int>&arr,vector<vector<int>>&dp,long long sum){
      
      if(n==0)
      return sum==0;
      
      if(dp[sum][n]!=-1)
      return dp[sum][n];
      
      if(arr[n-1]<=sum)
      return dp[sum][n]=(solve(n-1,arr,dp,sum-arr[n-1])%mod+solve(n-1,arr,dp,sum)%mod)%mod;
      else
      return dp[sum][n]=solve(n-1,arr,dp,sum)%mod;
      
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int sum=accumulate(arr.begin(),arr.end(),0);
        
        if((sum+d)%2)
        return 0;
        
        sum=((sum+d)/2)%mod;
        
        vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        
        return solve(n,arr,dp,sum)%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends