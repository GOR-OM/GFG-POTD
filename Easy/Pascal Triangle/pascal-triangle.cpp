//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
     vector<long long> nthRowOfPascalTriangle(int n) {
        int MOD = 1000000000+7;
        if(n == 1) return {1};
        if(n == 2) return {1, 1};
        
        vector<long long> prev(n, 1);
        vector<long long> cur(n, 1);
        
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j < i-1; ++j){
                cur[j] = (prev[j] + prev[j-1])%MOD;
            }
            prev = cur;
        }
        return cur;
        
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends