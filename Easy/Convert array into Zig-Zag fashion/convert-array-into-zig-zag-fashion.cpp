//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        vector<int>arr1=arr;
        sort(arr1.begin(),arr1.end());
        int i=1;
        int j=arr1.size()-1;
        if(n==1){
            return ;
        }
        for(int k=1;k<n;k++){
            if(k%2==0){
                arr[k]=arr1[i];
                i++;
            }
            else{
                arr[k]=arr1[j];
                j--;
            }
        }  
    }
};


//{ Driver Code Starts.

bool isZigzag(int n, vector<int> &arr) {
    int f = 1;

    for (int i = 1; i < n; i++) {
        if (f) {
            if (arr[i - 1] > arr[i])
                return 0;
        } else {
            if (arr[i - 1] < arr[i])
                return 0;
        }
        f = f ^ 1;
    }

    return 1;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;

        obj.zigZag(n, arr);
        bool check = 1;
        check = isZigzag(n, arr);
        if (check)
            cout << "1\n";
        else
            cout << "0\n";
    }
}

// } Driver Code Ends