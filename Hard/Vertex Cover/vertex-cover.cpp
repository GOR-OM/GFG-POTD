//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                
            vector<vector<int>>dp(n+1,vector<int>(1<<17,-1));
            function<int(int,int)>f=[&](int i,int mask)->int{
             
             
             if(i==n+1)
             {
                 set<int>s;
                 for(int i=1;i<=n;i++)
                 {
                     if(mask&(1<<i))
                     s.insert(i);
                 }
                 
                 for(auto it:edges)
                 {
                     if(s.find(it.first)==s.end() && s.find(it.second)==s.end())
                     return (int)(1e9);
                 }
                 
                 return (int)(s.size());
             }
             
             if(dp[i][mask]!=-1)
             return dp[i][mask];
             int res=min(f(i+1,mask),f(i+1,mask|(1<<i)));
             
             
             return dp[i][mask]= res;
            };
                
                
                return f(0,1);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends