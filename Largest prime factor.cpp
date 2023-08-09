
/*


░██████╗░  ░█████╗░  ██████╗░
██╔════╝░  ██╔══██╗  ██╔══██╗
██║░░██╗░  ██║░░██║  ██████╔╝
██║░░╚██╗  ██║░░██║  ██╔══██╗
╚██████╔╝  ╚█████╔╝  ██║░░██║
░╚═════╝░  ░╚════╝░  ╚═╝░░╚═╝


░█████╗░███╗░░░███╗
██╔══██╗████╗░████║
██║░░██║██╔████╔██║
██║░░██║██║╚██╔╝██║
╚█████╔╝██║░╚═╝░██║
░╚════╝░╚═╝░░░░░╚═╝




                   YAao,
                    Y8888b,
                  ,oA8888888b,
            ,aaad8888888888888888bo,
         ,d888888888888888888888888888b,
       ,888888888888888888888888888888888b,
      d8888888888888888888888888888888888888,
     d888888888888888888888888888888888888888b
    d888888P'                    `Y888888888888,
    88888P'                    Ybaaaa8888888888l
   a8888'                      `Y8888P' `V888888
 d8888888a                                `Y8888
AY/'' `\Y8b                                 ``Y8b
Y'      `YP                                    ~~
         `'

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define ha cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define fr(x,n) for(int i=x;i<n;i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
const long long mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;




//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N) {
    int ans = 1;

    while (N % 2 == 0) {
        ans = 2;
        N /= 2;
    }

    for (int i = 3; i * i <= N; i = i + 2) {
        while (N % i == 0) {
            ans = i;
            N /= i;
        }
    }

    if (ans == 1) {
        return N;
    }
    if(N>1)return max(ans,N);

    return ans;
}
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
