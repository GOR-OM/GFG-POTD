//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
     double fractionalKnapsack(int W, Item arr[], int n)
    {
        // greedy implementation of profit / weight ....
        vector<pair<double,int>> v(n);

        for(int i=0;i<n;i++){
            v[i]={arr[i].value/(1.0*arr[i].weight),i};
        }


        sort(v.begin(),v.end(),greater<pair<double,int>>());


        double wt=W,prof=0;
        int i;
        for(i=0;i<n;i++){
            double objwt= arr[v[i].second].weight;
            if( (wt - objwt) >= 0 ){
                wt = wt -objwt;
                prof+=( v[i].first*objwt);
            }
            else{
                prof+=(v[i].first *wt);
                break;
            }
        }
        return prof;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends