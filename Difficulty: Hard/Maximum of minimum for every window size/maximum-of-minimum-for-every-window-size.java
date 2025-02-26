//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String line = sc.nextLine();
            String[] input = line.split(" ");
            int[] arr = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            Solution solution = new Solution();
            ArrayList<Integer> result = solution.maxOfMins(arr);
            for (int val : result) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        // Your code here
        int n = arr.length;
        int[] nextsmaller =new int[n];
        int[] prevsmaller =new int[n];
        Stack<Integer> s =new Stack<>();
        int i=0 ;
        while(i<n)
        {
            if(s.isEmpty() || arr[i] >= arr[s.peek()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int v=s.pop();
                prevsmaller[v]=s.isEmpty()?-1:s.peek();
                nextsmaller[v]=i;
            }
        }
        while(!s.isEmpty())
        {
            int v=s.pop();
            prevsmaller[v]=s.isEmpty()?-1:s.peek();
            nextsmaller[v]=n;
        }
        
        ArrayList<Integer> ans = new ArrayList<>(n);
        for (int j = 0; j < n; j++) {
            ans.add(0);
        }
         for (int j=0; j < n; j++)
        {
            int len = nextsmaller[j] - prevsmaller[j] - 1;
            ans.set(len-1,Math.max(ans.get(len-1), arr[j]));
        }
        
        for (int j=n-2; j>=0; j--)
            ans.set(j,Math.max(ans.get(j), ans.get(j+1)));
        return ans;
    }
}