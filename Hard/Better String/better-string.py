#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def distinctSubsequences(self, s):
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        d = {}
        
        for i in range(1, n + 1):
            char = s[i - 1]
            dp[i] = dp[i - 1] * 2
            if char in d:
                idx = d[char]
                dp[i] -= dp[idx - 1]
            d[char] = i
        
        return dp[n] 
        
    def betterString(self, str1, str2):
        A = self.distinctSubsequences(str1)
        B = self.distinctSubsequences(str2)
        
        return str1 if A >= B else str2

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        str1 = input()
        str2 = input()
        ob = Solution()
        res = ob.betterString(str1, str2)
        print(res)
# } Driver Code Ends