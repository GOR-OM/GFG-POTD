//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        int grp = pow(2,r); // making group size
        int ind = n/grp; // choosing index from string which is responsible for answer
        char ch = s[ind]; // choosing that index
        string t;t+=ch;
        while(r--) // creating string after r operation using char ch;
        {
            string temp = "";
            for ( auto it:t ) {
                if(it=='1') temp+="10";
                else temp+="01";
            }
            t = temp;
            //cout<<t<<endl;
        }
        n%=grp; // updating n to lie within (0,grp_size)
        return t[n]; // return answer
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends