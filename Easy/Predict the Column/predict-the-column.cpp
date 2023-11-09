//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        int maximum = 0, col = -1;

        for(int j = 0; j < N; j++) {
            int count = 0;

            for(int i = 0; i < N; i++) 
                if(arr[i][j] == 0)
                    count++;

            if(maximum < count) {
                maximum = count;
                col = j;
            }
        }
        return col;
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends