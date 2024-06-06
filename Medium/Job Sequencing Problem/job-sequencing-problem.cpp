//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
   static bool compare(Job a1,Job a2){
    if(a1.profit==a2.profit)return a1.dead < a2.dead ;
    return a1.profit > a2.profit ;
}


 vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,compare);
         // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].dead > maxDeadline) {
            maxDeadline = arr[i].dead;
        }
    }

    // Step 2: Initialize an array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1);

    // Step 3: Iterate through the sorted jobs and find slots for them
    int jobCount = 0;
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                jobCount++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    // Return the total number of jobs done and the total profit
    return {jobCount, totalProfit};
}

    
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends