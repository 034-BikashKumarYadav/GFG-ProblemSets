//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
          int n = arr.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    for (int i = 0; i < n; i+=2) {
        arr[i] = pq.top();
        pq.pop();
    }
    int i = (n % 2 == 0) ? (n-1) : (n-2);
    while (i > 0) {
        arr[i] = pq.top();
        pq.pop();
        i -= 2;
    }
    return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends