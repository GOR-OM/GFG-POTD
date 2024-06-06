//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // cnt indicates the current number of platforms needed at a time
    int cnt = 0;
    // maxi indicates the maximum number of platforms needed
    int maxi = 0;

    int i = 0, j = 0;

    // Traverse through all the arrival and departure times
    while (i < n && j < n) {
        // If next event is an arrival, increment count of platforms needed
        if (arr[i] <= dep[j]) {
            cnt++;
            i++;
        }
        // Else, decrement count of platforms needed
        else {
            cnt--;
            j++;
        }
        // Update maxi to the maximum platforms needed so far
        maxi = max(maxi, cnt);
    }

    return maxi;
}
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends