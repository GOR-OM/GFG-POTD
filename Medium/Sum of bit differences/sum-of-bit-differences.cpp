//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
        // code here
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            long long num=arr[i];
            long long count=1;
            while(num){
                if(num%2){
                    mp[count]++;
                }
                num/=2;
                count++;
            }
        }
        
        long long ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans=ans+(n-it->second)*it->second*2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends