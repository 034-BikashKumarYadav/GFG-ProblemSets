//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String inputLine[] = br.readLine().trim().split(" ");
            int n = inputLine.length;
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            // calling method findMaxSum() of class solve
            System.out.println(new Solution().findMaxSum(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int findMaxSum(int arr[]) {
        // Edge case: if there's no house
        if (arr.length == 0) return 0;
        
        // Edge case: if there's only one house
        if (arr.length == 1) return arr[0];
        
        int n = arr.length;
        int[] dp = new int[n];
        
        // Base cases
        dp[0] = arr[0];
        dp[1] = Math.max(arr[0], arr[1]);
        
        // Fill the dp array
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i-1], arr[i] + dp[i-2]);
        }
        
        // Result is in dp[n-1]
        return dp[n-1];
    }
}