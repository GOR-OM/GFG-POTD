//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(string &s,int i,int j)
    {
        if(i>=j)
          return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
        {
            
           return  dp[i][j]=solve(s,i+1,j-1);
        }
       
        else{
           
            return dp[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
           
        }
        
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(S,0,n);
      
    } 
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends