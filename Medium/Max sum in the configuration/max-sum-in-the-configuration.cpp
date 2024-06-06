//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
   public:
    long long max_sum(int a[], int n) {
         long long sum = 0, product_sum = 0, ans = 0, N = n;
        for(int i = 0; i<n; i++){
            sum += a[i];
            product_sum += i*(long long)a[i];
        }
        ans = product_sum;
        for(int i = 1; i<n; i++){
            product_sum = (product_sum - sum) + a[(i + n - 1)%n]*(N);
            ans = max(ans, product_sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends