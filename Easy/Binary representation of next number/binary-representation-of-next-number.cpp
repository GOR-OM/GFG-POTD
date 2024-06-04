//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int cnt=0;
        //cleaning the string for zeros in the starting
        for(int i=0;i<s.size();){
            if(s[i]=='0'){
                s.erase(i,1);
            }else{
                break;
            }
        }
        
        // toggling the bits till we hit the rightmost zer0
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;
                s[i]='1';
                break;
            }else{
                s[i]='0';
            }
        }
        
        //case if no zero found
        if(cnt==0){
            s.insert(s.begin(),'1');
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends