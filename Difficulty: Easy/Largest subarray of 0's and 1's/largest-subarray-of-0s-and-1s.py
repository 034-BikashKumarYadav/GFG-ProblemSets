class Solution:
    def maxLen(self, arr):
        preSum={0:-1}
        currSum=0
        ans=0
        for i in range(len(arr)):
            currSum+= (1 if arr[i] else -1)
            if currSum in preSum:
                ans=max(ans,i-preSum[currSum])
            if currSum not in preSum:
                preSum[currSum]=i
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    a = list(map(int, input().split()))
    s = Solution().maxLen(a)
    print(s)

# } Driver Code Ends