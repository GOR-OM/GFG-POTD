//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
       for (int i = (n / 2) - 1; i >= 0; i--) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        // Check if left child exists and is greater than the current node
        if (left_child < n && arr[left_child] > arr[i]) {
            return false;
        }

        // Check if right child exists and is greater than the current node
        if (right_child < n && arr[right_child] > arr[i]) {
            return false;
        }
    }

    return true;
}
    
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends