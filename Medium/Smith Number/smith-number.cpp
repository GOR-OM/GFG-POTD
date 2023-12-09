//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        
        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        } 
        
        return sum;
    }

    int sumPrimes(int n) {
        int sum = 0, factors = 0, k = 2;
        while(n > 1) {
            if(n % k == 0) {
                sum += sumOfDigits(k);
                factors++;
                n /= k;
            } else
                k++;
        }
        
        return factors <= 1 ? 0 : sum; // composite number must have more than 1 factors;
    }

    int smithNum(int n) {
        int sumOfN = sumOfDigits(n);
        int sumOfPrimes = sumPrimes(n);
        return sumOfN == sumOfPrimes;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends