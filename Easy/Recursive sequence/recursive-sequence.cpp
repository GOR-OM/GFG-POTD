//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int md=1e9+7;
        if(n==1)
            return 1;
        int t=n*(n+1)/2;
        long long prod=1;
        for(int i=1;i<=n;i++)   // O(n)
        {
            prod *= ((t--)%md);
            prod %= md;
        }
        return ((prod%md)+sequence(n-1)%md)%md;     // o(n)
        // overall will be o(n*n)
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends