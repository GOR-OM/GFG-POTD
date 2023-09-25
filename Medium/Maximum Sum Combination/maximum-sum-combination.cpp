//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool check(int mid, int k, vector<int> &a, vector<int>&b){   
        int cnt=0;
        // how many pair whose sum >=mid
        for(auto x: a){
            cnt += b.end() - lower_bound(b.begin(), b.end(), mid-x);
        }
        return cnt>=k;
    }
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(b.begin(), b.end());
       
        int l=0, r= 2e4, sum=0;
        while(l<=r){
            int mid= (l+r)/2;
            if(check(mid, k, a, b)) sum=mid, l=mid+1;
            else r= mid-1;
        }
        
        vector<int> ans;
        for(int i=0; i< a.size(); i++){
            for(int j= n-1; j>=0; j--){
                if(a[i]+b[j] >= sum) ans.push_back(a[i]+b[j]);
                else break;
            }
        }
        
        sort(ans.rbegin(), ans.rend());
        while(ans.size()>k) ans.pop_back();
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends