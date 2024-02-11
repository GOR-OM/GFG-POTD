//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> result;
        unordered_map<int,int> track_nums;
        for(int i=0;i<n;i++){
            if(i == 0){
                result.push_back(0);
                track_nums[0]++;
            }
            else{
                int temp = result[i-1]-i;
                if(temp >= 0 && track_nums[temp] == 0){
                    result.push_back(temp);
                    track_nums[temp]++;
                }
                else{
                    temp = result[i-1]+i;
                    result.push_back(temp);
                    track_nums[temp]++;
                }
            }
        }
        return result;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends