//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
          vector<int> max_els;
        int n = arr.size();

        if (n == 0 || k <= 0) return max_els;
        if (k > n) k = n;

        int maxx = arr[0];
        for (int i = 0; i < k; ++i) {
            maxx = max(maxx, arr[i]);
        }
        max_els.push_back(maxx);

        for (int i = k; i < n; ++i) {
            if (arr[i - k] == maxx) {
                maxx = arr[i - k + 1];
                for (int j = i - k + 2; j <= i; ++j) {
                    maxx = max(maxx, arr[j]);
                }
            } else {
                maxx = max(maxx, arr[i]);
            }
            max_els.push_back(maxx);
        }

        return max_els;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends