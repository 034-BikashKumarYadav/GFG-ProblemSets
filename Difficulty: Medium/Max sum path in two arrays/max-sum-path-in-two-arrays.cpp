//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int i = 0, j = 0;
        int a1 = 0, a2 = 0;
        int Max = 0;
        int total = arr1.size() + arr2.size();
    
        for (int x = 0; x < total; x++) {
            if (i >= arr1.size() || j >= arr2.size()) break;
            if (arr1[i] < arr2[j]) {
                a1 += arr1[i];
                i++;
            } else if (arr2[j] < arr1[i]) {
                a2 += arr2[j];
                j++;
            } else {
                a1 += arr1[i];
                a2 += arr2[j];
                Max = max(Max + a1, Max + a2);
                a1 = 0;
                a2 = 0;
                i++;
                j++;
            }
        }
    
        for (int x = i; x < arr1.size(); x++) {
            a1 += arr1[x];
        }
        for (int y = j; y < arr2.size(); y++) {
            a2 += arr2[y];
        }
    
        Max = max(a1 + Max, a2 + Max);
        return Max;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends