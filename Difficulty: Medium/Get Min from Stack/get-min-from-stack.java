//{ Driver Code Starts
import java.util.*;

class Get_Min_From_Stack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // Number of test cases

        while (T-- > 0) {
            int q = sc.nextInt(); // Number of queries
            Solution g = new Solution();

            while (q-- > 0) {
                int qt = sc.nextInt();

                if (qt == 1) {
                    int att = sc.nextInt();
                    g.push(att);
                } else if (qt == 2) {
                    g.pop(); // Just call pop(), do not print anything
                } else if (qt == 3) {
                    System.out.print(g.peek() + " "); // Print top element
                } else if (qt == 4) {
                    System.out.print(g.getMin() + " "); // Print minimum element
                }
            }
            System.out.println("\n~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    private Stack<Integer> st;
    private Stack<Integer> mn;

    public Solution() {
        st = new Stack<>();
        mn = new Stack<>();
    }

    public void push(int x) {
        st.push(x);
        int top = mn.isEmpty() ? Integer.MAX_VALUE : mn.peek();
        mn.push(Math.min(x, top));
    }

    public void pop() {
        if (!st.isEmpty()) {
            st.pop();
            mn.pop();
        }
    }

    public int peek() {
        return st.isEmpty() ? -1 : st.peek();
    }

    public int getMin() {
        return mn.isEmpty() ? -1 : mn.peek();
    }
}
