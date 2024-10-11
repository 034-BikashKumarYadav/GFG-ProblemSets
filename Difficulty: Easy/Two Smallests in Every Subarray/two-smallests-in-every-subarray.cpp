//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
         if (arr.size() < 2) return -1;

    int maxSum = -1;

    // Traverse the array considering each adjacent pair
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int firstMin = min(arr[i], arr[i + 1]);
        int secondMin = max(arr[i], arr[i + 1]);
        int sum = firstMin + secondMin;
        maxSum = max(maxSum, sum);
    }

    return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends