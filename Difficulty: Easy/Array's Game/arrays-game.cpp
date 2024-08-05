//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string arrayGame(int N, int A[]) {
        int maxi=0;
        long long sum=0;
        for(int i=0;i<N;i++){
            maxi = max(A[i],maxi);
        }
        for(int i=0;i<N;i++){
            sum+=maxi-A[i];
        }
        if(sum==0){
            return "Draw";
        }
        if(sum%2==0 ){
            return "Second";
        }
         if(sum%2!=0 ){
             return "First" ;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, i;
        cin >> N;
        int A[N];
        for (i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.arrayGame(N, A) << "\n";
    }
}
// } Driver Code Ends