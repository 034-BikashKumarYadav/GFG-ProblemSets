# User function Template for python3

import math
class Solution:
    def longestSubarray(self, arr, k):  
        n=len(arr)
        d={0:[-1]}
        summ=0
        maxi=-math.inf

        for i in range(n):
            summ+=arr[i]
            if summ-k in d:
                for j in  (d[summ-k]):
                    # print(i,j)
                    maxi=max(maxi,i-j)
        
            if summ in d:
                d[summ].append(i)
            else:
                d[summ]=[i]
    
        # print(d)

        if maxi!=-math.inf:
            return maxi
        return 0



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        tc -= 1
        print("~")
# } Driver Code Ends