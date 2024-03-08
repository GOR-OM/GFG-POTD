//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
bool sameFreq(string s)
{
    int c=0,mini=INT_MAX;
    unordered_map<int,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    for(auto x:mp)
    {
        mini=min(mini,x.second);
    }
    for(auto x:mp)
    {
        if(x.second==(mini+1))
        {
            c+=1;
        }
     else if(x.second>=(mini+2))
     return 0;
    }
   if(c>1)
   {
       if(mini==1)
       return 1;
       else
        return 0;
   }
   else
   return 1;
    // code here 
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends