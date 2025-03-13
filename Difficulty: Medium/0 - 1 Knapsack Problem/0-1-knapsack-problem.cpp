//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
      int fun(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(i<0 || W<0)    
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        
        int t = 0;
        int nt = fun(i-1, W, val, wt, dp);
        
        if(wt[i] <= W)
            t = val[i] + fun(i-1, W-wt[i], val, wt, dp);
        
        return dp[i][W] = max(t, nt);
    }
    public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        return fun(n-1, W, val, wt, dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends