//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    pair<int,string> helper(int i,int j,int p[],map<int,string>&m,vector<vector<int>>&dpforInt,vector<vector<string>>&dpforStr)
    {
        
        if(j-i==0)
        {
            return {0,m[i]};
        }
        else if(j-i==1)
        {
            return {p[i]*p[i+1]*p[j+1],"("+m[i]+m[j]+")"};
        }
        else
        {
            if(dpforInt[i][j]!=-1)
            {
                return {dpforInt[i][j],dpforStr[i][j]};
            }
            int ans=INT_MAX;
            string str="";
            for(int k=i;k<=j-1;k++)
            {
                pair<int,string>p1=helper( i, k, p, m,dpforInt,dpforStr);
                pair<int,string>p2=helper( k+1, j, p, m,dpforInt,dpforStr);
                int temp=p[i]*p[k+1]*p[j+1];
                if(temp+p1.first+p2.first<ans)
                {
                    ans=temp+p1.first+p2.first;
                    str="("+p1.second+p2.second+")";
                }
            }
            dpforInt[i][j]=ans;
            dpforStr[i][j]=str;
            return {ans,str};
        }
    }
    string matrixChainOrder(int p[], int n){
        map<int,string>m;
        string str="A";
        for(int i=0;i<=n-2;i++)
        {
            
            if(i!=0)
            {
                str[0]++;
            }
            m[i]=str;
        }
        vector<vector<int>>dpforInt(n+1,vector<int>(n+1,-1));
        vector<vector<string>>dpforStr(n+1,vector<string>(n+1,""));
        return helper(0,n-2, p,m,dpforInt,dpforStr).second ;
    }
};



//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends