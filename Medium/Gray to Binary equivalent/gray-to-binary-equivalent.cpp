//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
         string gray="";
        while(n!=0){
            if(n%2==1) gray+='1';
            else if(n%2==0) gray+='0';
            n=n/2;
        }
        reverse(gray.begin(),gray.end());
        string binary="";
        int len=gray.length();
        
        binary+=gray[0];
        
       for(int i=1;i<len;i++){
           if(binary[i-1]!=gray[i]){
               binary+='1';
           }
           else{
               binary+='0';
           }
       }
       
       
       int p=1,num=0;
       for(int i=len-1;i>=0;i--){
           if(binary[i]=='1'){
               num+=p;
           }
           p=p*2;
       }
        
        return num;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends