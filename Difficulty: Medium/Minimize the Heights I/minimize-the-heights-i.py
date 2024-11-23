#User function Template for python3

class Solution:
    def getMinDiff(self, k, arr):
        if not arr:
            return 0
        
        # Sort the array
        arr.sort()
        
        # Calculate initial difference
        n = len(arr)
        initial_diff = arr[-1] - arr[0]
        
        # Initialize smallest and largest after changes
        smallest = arr[0] + k
        largest = arr[-1] - k
        
        # Iterate through the array
        for i in range(n - 1):
            min_height = min(smallest, arr[i + 1] - k)
            max_height = max(largest, arr[i] + k)
            initial_diff = min(initial_diff, max_height - min_height)
        
        return initial_diff




#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.getMinDiff(k, arr)
        print(res)
        print("~")

# } Driver Code Ends