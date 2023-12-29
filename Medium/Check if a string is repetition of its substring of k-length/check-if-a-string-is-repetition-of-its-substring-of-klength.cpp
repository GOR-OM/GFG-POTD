//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
{
// if n is not divisible by k return 0; 
    if((n % k) != 0)
        return 0;
    map<string, int> subString;
       for(int i{0}; i < n; i += k){
// storing the number of substring appeared to substring
           subString[s.substr(i, k)]++; 
// return 0 if there are more than 2 different substring
           if(subString.size() > 2) 
               return 0;
       }
       int res{0};
// increase res if number of subString appeared is more than 1 times
// to make sure one of the two subString is not more than 1...
// if it is than we will handle it at the time of return statement...
       for(const auto& pair : subString){
           if(pair.second > 1) res++;
       }
// if(res > 1) return 0; else return 1;
       return res > 1 ? 0 : 1; 
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends