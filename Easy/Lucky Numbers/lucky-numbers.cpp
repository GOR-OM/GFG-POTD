//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool check( int n , int div)
    {
        if( div > n)
        {
            return true;
        }
        
        if( n % div == 0)
        {
            return false;
        }
        else
        {
            return check(n-(n/div) , div + 1);
        }
    }
    
    bool isLucky(int n) {
        
        return check(n , 2);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends