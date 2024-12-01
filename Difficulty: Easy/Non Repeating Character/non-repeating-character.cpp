//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
         unordered_map<char, int> countMap;
        // Count frequency of each character
        for (char c : s) {
            countMap[c]++;
        }
        // Find the first non-repeating character
        for (char c : s) {
            if (countMap[c] == 1) {
                return c;
            }
        }
        return '$'; // No non-repeating character found
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends