//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(string &wild,string &pattern,int w,int p,vector<vector<int>> &dp)
    {
        if(w<0 &&  p<0)
        return true;
        
        if(w<0 && p>=0)
        return false;
        
        if(w>=0 && p<0)
        {
            for(int k=0;k<=w;k++)
            {
                if(wild[k]!='*')
                return false;
            }
            return true;
        }
        
        if(wild[w]==pattern[p] || wild[w]=='?')   
        {
            return dp[w][p]=solve(wild,pattern,w-1,p-1,dp);
        }
        
        if(wild[w]=='*')
        {
            return dp[w][p]=(solve(wild,pattern,w-1,p,dp) | solve(wild,pattern,w,p-1,dp));
        }

   return false;
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        int m=pattern.size();
        int n=wild.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(wild,pattern,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends