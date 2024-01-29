//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int f(string &str,int i,int sum,vector<vector<int>>&dp)
    {
        if(i >= str.length())return 1;
        if(dp[i][sum] != -1)return dp[i][sum];
        
        int curr_sum = 0;
        int ways = 0;
        
        for(int index = i ; index < str.length() ; index++)
        {
            curr_sum = curr_sum + (str[index] - '0');
            
            if(curr_sum >= sum)
            {
                ways = ways + f(str,index+1,curr_sum,dp);
            }
        }
        
        return dp[i][sum] = ways;
    }
    
	public:
	int TotalCount(string str)
	{
	    int total_sum = 0;
	    
	    for(char it : str)
	    {
	        total_sum += (it - '0');
	    }
	    
	    vector<vector<int>>dp(str.length(),vector<int>(total_sum+1,-1));
	    return f(str,0,0,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends