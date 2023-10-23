//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
	public int maxSumIS(int arr[], int n)  
	{  
	    //code here.
	   // int[][] dp = new int[n+1][n+1];
	    
	   // for(int idx=0; idx<n+1; idx++){
	   //     Arrays.fill(dp[idx], -1);
	   // }
	    
	    return Tabulation(arr, n);
	}  
	
	public int solve(int[] arr, int size, int curr, int prev, int[][] dp) {
	    if(curr==size) {
	        return 0;
	    }
	    
	    if(dp[curr][prev+1]!=-1){
	        return dp[curr][prev+1];
	    }
	    
	    int include = Integer.MIN_VALUE;
	    if(prev==-1 || arr[curr]>arr[prev]){
	        include = arr[curr]+solve(arr, size, curr+1, curr, dp);
	    }
	    
	    int exclude = solve(arr, size, curr+1, prev, dp);
	    
	    return dp[curr][prev+1]=Math.max(include, exclude);
	}
	
	public int Tabulation(int[] arr, int size) {
	    int[] dp = new int[size];
	    int ans = Integer.MIN_VALUE;
	    for(int idx=0; idx<size; idx++) {
	        dp[idx] = arr[idx];
	    }
	    
	    for(int idx1=0; idx1<size; idx1++) {
	        for(int idx2=0; idx2<idx1; idx2++) {
	            if(arr[idx1]>arr[idx2]){
	                dp[idx1] = Math.max(dp[idx2]+arr[idx1], dp[idx1]);
	            }
	        }
	        ans = Math.max(ans, dp[idx1]);
	    }
	    
	    return ans;
	}
}
	