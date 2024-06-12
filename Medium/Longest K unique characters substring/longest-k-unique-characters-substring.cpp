//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string S, int K) {
     int n = S.length();
    int left = 0; // Left pointer of the window
    int maxLength = -1; // Max length of the window
    unordered_map<char, int> charFreq; // To store the frequency of characters in the window

    for (int right = 0; right < n; ++right) {
        // Include the character at right in the window
        charFreq[S[right]]++;

        // Shrink the window from the left until we have K unique characters
        if (charFreq.size() > K) {
            charFreq[S[left]]--;
            if (charFreq[S[left]] == 0) {
                charFreq.erase(S[left]);
            }
            left++;
        }
        else if(charFreq.size() == K) {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    return maxLength;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends