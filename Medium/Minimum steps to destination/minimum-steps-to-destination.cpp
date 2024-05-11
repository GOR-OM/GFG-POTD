//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int target) {
        int sum = 0;
        int step = 0;
        
        while (sum < target) {
            step++;
            sum = sum + step;
        }
        
        while ((sum - target) & 1) {
            sum = sum - (2 * (sum - target));
            step++;
            sum = sum + step;
        }
        
        return step;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends