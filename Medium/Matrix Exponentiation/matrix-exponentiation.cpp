//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    const long long MOD = 1e9+7;
    vector<vector<long long>> multipliesMatrix(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    int size = a.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += (a[i][k] * b[k][j])%MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> func(vector<vector<long long>>&a, long long  n) {
    if (n == 1) return a;
    vector<vector<long long>> temp = func(a, n / 2);
    if (n % 2 == 0) {
        return multipliesMatrix(temp, temp);
    }
    return multipliesMatrix(multipliesMatrix(temp, temp), a);
}

int FindNthTerm(long long int n) {
    vector<vector<long long>> a = {{1, 1}, {1, 0}};
    vector<vector<long long>> ans = func(a, n);
    return ans[0][0] % MOD;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends