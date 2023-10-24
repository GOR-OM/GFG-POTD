//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>dp;
    int f(int i,string &str,unordered_map<int,vector<int>>&mp)
    {
        if(i==str.size())
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int mi=502;
        for(auto &it:mp[i])
        {
            mi=min(mi,1+f(it+1,str,mp));
        }
        return dp[i]=mi;
    }
    int palindromicPartition(string str)
    {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<str.size();i++)
        {
            int j=i,k=i;
            while(j>=0 && k<str.size() && str[k]==str[j])
            {
                mp[j].push_back(k);
                k++;j--;
            }
            if(i+1<str.size())
            {
                j=i;k=i+1;
                while(j>=0 && k<str.size() && str[k]==str[j])
                {
                    mp[j].push_back(k);
                    k++;j--;
                }
            }
        }
        dp.resize(str.size()+1,-1);
        return f(0,str,mp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends