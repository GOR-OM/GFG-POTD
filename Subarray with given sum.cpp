
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


// vector<int> subarraySum(vector<int>arr, int n, long long s){
//     map<int,long long >mp;
//     vector<int>ans;
//     long long sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum==s){
//             ans.pb(1);
//             ans.pb(i+1);
//             return ans;
//         }
//         if(mp.find(sum-s)!=mp.end()){
//             ans.pb(mp[sum-s]+1);
//             ans.pb(i+1);
//             return ans;
//         }
//         mp[sum]=i+1;
//     }
//     return ans;

// }


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
              if(s==0)return {-1};
        int l=0,r=0;
        long long sum=arr[0];
        vector<int>ans;
        while(r<n){
            if(sum<s){
                if(r<n-1){
                    r++;
                    sum+=arr[r];
                }
                else return {-1};
            }
            else if(sum>s){
                sum-=arr[l];
                l++;
            }
            else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends