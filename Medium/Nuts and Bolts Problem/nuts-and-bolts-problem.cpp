//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

   void matchPairs(int n, char nuts[], char bolts[]) {
       vector<int>v(64, 0);
       for(int i=0; i<n; i++){
           v[nuts[i] - '!']++;
       }
       int j =0;
       for(int i=0; i<64; i++){
           while(v[i] != 0){
               nuts[j] = static_cast<char>(i + 33);
               bolts[j] = static_cast<char>(i + 33);
               v[i]--;
               j++;
           }
       }
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends