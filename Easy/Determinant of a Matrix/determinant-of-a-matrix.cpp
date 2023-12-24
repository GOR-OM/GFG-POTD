//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
     int determinantOfMatrix(vector<vector<int>> matrix, int n)
    {
        // code here 
        if(n==1)
        return matrix[0][0];
        if(n==2){
            return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        }
        
        int ans =0;
        for(int i=0;i<n;i++){
            vector<vector<int>>temp;
            for(int j=1;j<n;j++){
                vector<int>v;
                for(int k=0;k<n;k++){
                    if(k==i)
                      continue;
                    else{
                        v.push_back(matrix[j][k]);
                    }
                }
                temp.push_back(v);
            }
            
            if(i&1)
            ans -= matrix[0][i]*determinantOfMatrix(temp,n-1);
            else
            ans += matrix[0][i]*determinantOfMatrix(temp,n-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends