#User function Template for python3

class Solution:
    def productExceptSelf(self, arr):
        a=[]
        l=1
        p=1
        k=[]
        c=0
        for i in range(len(arr)):
            l=l*arr[i]
            if arr[i]==0:
                c+=1
            else:
                k.append(arr[i])
        for i in k:
            p=p*i
        if c>1:
            for i in range(len(arr)):
                a.append(0)
        elif 0 in arr:
            for i in arr:
                if i==0:
                    a.append(p)
                else:
                    a.append(0)
        else:
            for i in arr:
                a.append(l//i)
        return(a)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends