//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int K) 
    { 
       int l=0;
       int r= N-1;
       while(l<=r){
           int w1 = l + (r-l)/3;
           int w2 = r - (r-l)/3;
           if(arr[w1]==K)return 1;
           if(arr[w2]==K)return 1;
           
           if(arr[w1]>K){
               r=w1-1;
           }
           else if(arr[w2]<K){
               l= w2+1;
           }
           else {
               l=w1+1;
               r=w2-1;
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        
        int arr[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;

    }

	return 0; 
} 

// } Driver Code Ends