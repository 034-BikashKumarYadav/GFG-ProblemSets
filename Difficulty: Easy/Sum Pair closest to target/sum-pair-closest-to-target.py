class Solution:
    def sumClosest(self, arr, target):
        # code here
        minn=float('inf')
        res=[]
        arr.sort()
        l,r=0,len(arr)-1
        while l<r:
            cur=arr[l]+arr[r]
            if abs(target-cur)<minn:
                minn=abs(target-cur)
                res=[arr[l],arr[r]]
            elif abs(target-cur)==minn:
                if arr[r]-arr[l]>res[1]-res[0]:
                    res=[arr[l],arr[r]]
            if cur<target:
                l+=1
            else:
                r-=1
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        arr = list(map(int, input().strip().split()))
        target = int(input().strip())
        ob = Solution()
        ans = ob.sumClosest(arr, target)
        if not ans:
            print("[]")
        else:
            print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends