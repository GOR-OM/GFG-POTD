//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
        if(n <= 2) return 1;
        int priro1 = 1,priro2 = 1,priro3 = 1,curr;
        for(int i = 3; i <= n; i++) {
            curr = (priro2 + priro3)%(int)(1e9 + 7);
            priro3 = priro2;
            priro2 = priro1;
            priro1 = curr;
        }
        return curr;
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
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends