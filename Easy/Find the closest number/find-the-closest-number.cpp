//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int ans=0;
       
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(abs(arr[i]-k)<mini){
                mini = abs(arr[i]-k);
                ans= arr[i];
                
            }
            else if(abs(arr[i]-k)==mini){
                ans = max(arr[i],ans);
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends