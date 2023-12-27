//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int size=matrix.size();
        vector<int>ans;
        if(size==0) return ans;
        ans.push_back(matrix[0][0]);
        if(size==1) {
            return ans;
        }
        
        for(int i=1;i<size;i++){
            int row=0,col=i;
            while(row<size && col>=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        for(int i=1;i<size-1;i++){
            int row=i,col=size-1;
            while(row<size && col>=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        ans.push_back(matrix[size-1][size-1]);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends