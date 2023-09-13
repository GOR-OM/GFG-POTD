//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans;
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=9;j>=0;j--) 
            {
                if(S-j>=0) 
                {
                    ans+=to_string(j);
                    S-=j;
                    break;
                }
            }
        }
        if(S) return "-1";
        if(N==1)
        return ans;
        else if(ans[0]=='0') return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends