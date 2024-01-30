//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int dp[21][21][21];
        int solve(string& A, string& B, string& C, int i, int j, int k){
            int n1 = A.size(), n2 = B.size(), n3 = C.size();
            if(i >= n1 || j >= n2 || k >= n3) return 0;
            if(dp[i][j][k] != -1) return dp[i][j][k];
            if(A[i] == B[j] && B[j] == C[k])
                return dp[i][j][k] = solve(A, B, C, i+1, j+1, k+1) + 1;
            return dp[i][j][k] = max({solve(A, B, C, i+1, j, k), solve(A, B, C, i, j+1, k), solve(A, B, C, i, j, k+1)}) ;
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            memset(dp, -1, sizeof(dp));
            return solve(A, B, C, 0, 0, 0);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends