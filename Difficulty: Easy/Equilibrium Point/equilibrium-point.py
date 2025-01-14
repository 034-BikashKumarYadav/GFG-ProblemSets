# User function Template for python3

class Solution:
    #Function to find equilibrium point in the array.
    def findEquilibrium(self, arr):
        # code here
        lp,rp=[0]*len(arr),[0]*len(arr)
        ls=rs=0
        for i in range(len(arr)):
            ls+=arr[i]
            rs+=arr[len(arr)-1-i]
            lp[i]=ls
            rp[len(arr)-1-i]=rs
        for i in range(len(arr)):
            if lp[i]==rp[i]:
                return i
        return -1




#{ 
 # Driver Code Starts
#Initial Template for Python 3
import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.findEquilibrium(arr))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends