//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
      int buyMaximumProducts(int n, int totalMoney, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({price[i], i+1});
        }
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int count = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
            int buyingCount = v[i].second;
            while(totalMoney >= v[i].first && buyingCount != 0) {
                count++;
                buyingCount--;
                totalMoney -= v[i].first;
            }
            
            if(totalMoney < v[i].first)
                return count;
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends