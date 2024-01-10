//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    
	    for(int i=0;i<n;i++)
	    {
	        int x=abs(arr[i]);
	        x=(x+k-1)/k;
	        arr[i]=(arr[i]+x*k)%k;
	    }
	    vector<int>prefix(n,0);
	    prefix[0]=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        prefix[i]=(prefix[i-1]+arr[i]+k)%k;
	    }
	    map<int,int>mp;
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        if(prefix[i]==0)
	        {
	            res=max(res,i+1);
	        }
	        if(mp.find(prefix[i])!=mp.end())
	        {
	            res=max(res,i-mp[prefix[i]]);
	        }
	        if(mp.find(prefix[i])==mp.end())
	        {
	            mp[prefix[i]]=i;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends