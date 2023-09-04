//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

vector<pair<int,int>>moves={
    {1,0},{0,1},{-1,0},{0,-1}
};

void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&mat){
    
    vis[i][j] =1;
    for(auto child : moves){
        int p_x = i + child.first;
        int p_y = j + child.second;
        if(p_x<0 || p_y<0 || p_x>=n || p_y>=m || mat[p_x][p_y]=='X')continue;
        if(!vis[p_x][p_y]){
            dfs(p_x,p_y,n,m,vis,mat);
        }

    }
}



vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0]=='O'){
            dfs(i,0,n,m,vis,mat);

        }
        if(!vis[i][m-1] && mat[i][m-1]=='O'){
            dfs(i,m-1,n,m,vis,mat);
        }
    }
    for(int j=0;j<m;j++){
        if(!vis[0][j] && mat[0][j]=='O'){
            dfs(0,j,n,m,vis,mat);

        }
        if(!vis[n-1][j]&& mat[n-1][j]=='O'){
            dfs(n-1,j,n,m,vis,mat);
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
           if(mat[i][j]=='O' && vis[i][j]==0){
            mat[i][j]='X';
           } 
            
        }
    }
    return mat;


}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends