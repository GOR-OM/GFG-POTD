//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int help(int taken,int start,int &limit,int &n){
        if(taken==n)return 1;
        if(start > limit)return 0;
        int temp=0;
        for(int i=2*start;i<=limit;i++){
            temp+=help(taken+1,i,limit,n);
        }
        return temp;
    }
    int numberSequence(int m, int n){
        int res=0;
        for(int i=1;i<=m;i++){
            int temp=help(1,i,m,n);
            if(temp==0)break;
            res+=temp;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends