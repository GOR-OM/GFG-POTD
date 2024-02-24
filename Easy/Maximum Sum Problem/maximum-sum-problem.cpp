//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
       int maxSum(int n)
        {
            if(n == 0)
                return 0;

            int a = max(n/2, maxSum(n/2));
            int b = max(n/3, maxSum(n/3));
            int c = max(n/4, maxSum(n/4));
            
            return max(n, a+b+c);
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends