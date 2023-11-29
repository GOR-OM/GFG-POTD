//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n)
    {
        //may2021
        
        int count=0;
        
        while(n)
         {
             if(n/3) count+=1;
             count+=n%3;
             n=n/3;
             if(n==1) break;
             if(n==2) return ++count;
         }
        
        
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends