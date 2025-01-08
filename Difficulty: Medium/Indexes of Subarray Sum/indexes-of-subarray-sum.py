#User function Template for python3
class Solution:
    def subarraySum(self, arr, target):
        pfs=arr[:]
        lth=len(pfs)
        seen={0:-1}
        for ix in range(lth):
            pfs[ix]+=pfs[ix-1] if ix-1>=0 else 0
            if pfs[ix]-target in seen:
                return [seen[pfs[ix]-target]+2,ix+1]
            seen[pfs[ix]]=ix
        return [-1]


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        d = int(input().strip())
        ob = Solution()
        result = ob.subarraySum(arr, d)
        print(" ".join(map(str, result)))
        tc -= 1
        print("~")

# } Driver Code Ends