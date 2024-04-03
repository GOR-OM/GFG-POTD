//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool solve(vector<int> adj[] , vector<int>& vis, vector<int>& pathVis, vector<int>&check,int i ){
    vis[i]=1;
    pathVis[i]=1;
    
    for(auto j : adj[i]){
        if(!vis[j]){
            if(solve(adj,vis,pathVis,check,j)){
                    check[i]=0;
                    return true;
            }
            
        }
        else if(pathVis[j]){
                check[i]=0;
                return true;
            }
    }
    check[i]=1;
    pathVis[i]=0;
    return false;
}

    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
         vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int>check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(adj, vis,pathVis,check,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends