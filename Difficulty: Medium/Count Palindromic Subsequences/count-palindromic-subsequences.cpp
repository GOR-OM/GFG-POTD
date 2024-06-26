//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    vector<vector<int>> dp;
    const int MOD = 1e9 + 7;

    long long solve(const string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = (solve(s, i + 1, j) + solve(s, i, j - 1) + 1) % MOD;
        } else {
            long long res = (solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1)) % MOD;
            // Ensure the result is non-negative
            if (res < 0) res += MOD;
            return dp[i][j] = res;
        }
    }
    
    
    long long int countPS(const string &str) {
        int n = str.length();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(str, 0, n - 1);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends