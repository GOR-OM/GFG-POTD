//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    long long mod=1e9+7;
	    vector<long long>dp(n+1,0);
	    dp[0]=1,dp[1]=2;
	    for(int i=2;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
	    return dp[n]%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends