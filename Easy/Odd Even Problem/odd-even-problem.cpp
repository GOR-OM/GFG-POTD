//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) 
    {
        map<int,int> mp;
        int x = 0;
        int y = 0;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]-'a' + 1]++;     // store the frequency of each charachter with key as postition in alpahabets (a-z)
        }
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if((itr->first)%2 == 0 && (itr->second)%2 == 0) // calculate the sum of charachter which are at even position in alphabet and has even frequency
                x++;
            else if((itr->first)%2 != 0 && (itr->second)%2 != 0)  // calculate the sum of charachter which are at odd position in alphabet and has odd frequency
                y++;
        }
        if((x + y) % 2 == 0)
            return "EVEN"; // return EVEN if summation of x and y is even
        else
            return "ODD"; // return ODD if summation of x and y is even
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends