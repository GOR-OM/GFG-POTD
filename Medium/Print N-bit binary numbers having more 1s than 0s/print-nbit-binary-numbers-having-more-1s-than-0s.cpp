//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	 void help(int n,string s,int countOne,vector<string>& ans)
    {
        //base case
        if(n==0)
        {
            ans.push_back(s);
            return ;
        }
        
        //recursive calls
        //and small calculation
        help(n-1,s+'1',countOne+1,ans);
        if(countOne>0)
        help(n-1,s+'0',countOne-1,ans);
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    help(n,"",0,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends