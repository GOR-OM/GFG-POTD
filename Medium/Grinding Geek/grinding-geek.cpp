//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     int dp[1001][1001];
     
    int func(int ind,int total,vector<int>&cost,int n){
        if(ind==n)return 0;
        if(dp[ind][total]!=-1) return dp[ind][total];
        int notpick=func(ind+1,total,cost,n);
        int pick=0;
        if(cost[ind]<=total)pick=1+func(ind+1,total-cost[ind]+(cost[ind]*9)/10,cost,n);
        return dp[ind][total]=max(pick,notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        memset(dp,-1,sizeof(dp));
        return func(0,total,cost,n);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends