//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	// Code here
        int ans=0;
	vector<int> arr(b+1,1);
        //Sieve of Eratosthenos
	for(int i=2;i<=b;i++) if(arr[i]){
	    for(long long j=1LL*i*i;j<=b;j+=i) arr[j]=0;
	}
        //Now we store counts
	for(int i=2;i<=b;i++) if(arr[i]){
	    for(long long val=i;val<=b;val*=i){
	        ans+=b/val - (a-1)/val;
	    }
	}
       return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends