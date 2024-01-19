//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& a, int N, int K) {
        // code here
        vector<vector<int>> final_ans;
        vector<int> top(K + 1, 0);
        unordered_map<int, int> freq;
    
        for (int m = 0; m < N; ++m) {
            if (freq.find(a[m]) != freq.end()) {
                freq[a[m]] += 1;
            } else {
                freq[a[m]] = 1;
            }
    
            top[K] = a[m];
            int i = find(top.begin(), top.end(), a[m]) - top.begin() - 1;
    
            while (i >= 0) {
                if (freq[top[i]] < freq[top[i + 1]]) {
                    swap(top[i], top[i + 1]);
                } else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1])) {
                    swap(top[i], top[i + 1]);
                } else {
                    break;
                }
                i -= 1;
            }
    
            i = 0;
            vector<int> ans;
            while (i < K && top[i] != 0) {
                ans.push_back(top[i]);
                i += 1;
            }
    
            final_ans.push_back(ans);
        }
    
        return final_ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends