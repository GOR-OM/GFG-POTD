//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1000][1000];
    int help(vector<vector<int> > &M,int currX, int currY, int Msize, int Nsize){
        if(currX<0) return 0;
        if(currX>=Msize || currY>=Nsize){
            return dp[currX][currY]=0;
        }
        if(dp[currX][currY]!=-1) return dp[currX][currY];
        
        if(currX==0) return dp[currX][currY] = M[currX][currY]+max(help(M, currX, currY+1,Msize,Nsize),help(M,currX+1, currY+1,Msize,Nsize));
        
        return dp[currX][currY] = M[currX][currY]+max(max(help(M, currX, currY+1,Msize,Nsize),help(M,currX+1, currY+1,Msize,Nsize)),
                                        
                                    help(M,currX-1,currY+1,Msize,Nsize));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        
        int Msize = M.size();
        int Nsize = M[0].size();
        
        int ans = 0;
        int temp = 0;
        
        for(int i=0;i<Msize;i++){
            // cout<<
            ans = max(ans,help(M,i,0,Msize,Nsize));
            // cout<<ans<<'\n';
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends