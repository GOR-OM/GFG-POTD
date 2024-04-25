//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int x = 0;
        int y = 1;
        int prevX = 0;
        int prevY = 0;
        while(i < n && j < m && i >=0 && j >= 0){
            if(matrix[i][j] == 0){
                prevX = i;
                prevY = j;
                i += x;
                j += y;
            }
            else{
                matrix[i][j] = 0;
                if(x == 0 && y == 1){
                    x = 1;
                    y = 0;
                }
                else if(x == 1 && y == 0){
                    y = -1;
                    x = 0;
                }
                else if(x == 0 && y == -1){
                    x = -1;
                    y = 0;
                }
                else{
                    y = 1;
                    x = 0;
                }
            }
        }
        ans.push_back(prevX);
        ans.push_back(prevY);
        return ans;
     }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends