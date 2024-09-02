//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

    // If the array has only one element, no jumps are needed
    if (n <= 1) return 0;

    // If the first element is 0, we can't move anywhere
    if (arr[0] == 0) return -1;

    // Initialize variables
    int jumps = 0;
    int currentEnd = 0; // The farthest position we can reach with current number of jumps
    int farthest = 0;   // The farthest position we can reach with one more jump

    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest point that can be reached
        farthest = max(farthest, i + arr[i]);

        // If we have reached the currentEnd, it's time to jump
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            // If we reach or exceed the last index, return the jump count
            if (currentEnd >= n - 1) return jumps;
        }
    }

    // If we never reach the end, return -1
    return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends