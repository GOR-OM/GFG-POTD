//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<pair<int,int>> moves={
    {1,0},{0,1},{-1,0},{0,-1}
};

void dfs(int i, int j, int k, vector<vector<int>>& ans, int color){
    int n = ans.size();
    int m = ans[0].size();
    
    if(i < 0 || j < 0 || i >= n || j >= m || ans[i][j] != k) {
        return;  // Base case: out of bounds or not matching color
    }
    
    ans[i][j] = color;

    for(auto child : moves){
        int p_x = i + child.first;
        int p_y = j + child.second;

        dfs(p_x, p_y, k, ans, color);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int k = image[sr][sc];
    if (k != color) {
        dfs(sr, sc, k, image, color);
    }
    return image;    
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends