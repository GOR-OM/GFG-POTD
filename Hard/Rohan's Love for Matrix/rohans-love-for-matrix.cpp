//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int firstElement(int n) {
        // code here
        int a[n];
        a[0]=1;
        a[1]=2;
        for(int i=2;i<n;i++){
            a[i]=(a[i-1]%1000000007)+(a[i-2]%1000000007);
        }
        if(n==1){
            return 1;
        }
        return a[n-2]%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends