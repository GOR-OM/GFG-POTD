//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
    {
        // Code here
        const int M = 1000000007;
        vector<long long> dp(N+1);
        dp[1] = 2;
        dp[2] = 3;
        for(int i = 3;i <= N;++i){
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] = dp[i] % M;
        }
        return ((dp[N]%M) * (dp[N]%M))%M;
    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends