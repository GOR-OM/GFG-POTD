//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   long long reversedBits(long long x) {
        long long ans = 0;
        int pos = 0;
        
        while(x){
            if(x&1) ans += (unsigned int)1<<(31-pos);
            pos++;
            x >>= 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends