//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int> firstOccurrence; // To store the first occurrence index of each element
        int maxDist = 0; // To store the maximum distance
        
        for (int i = 0; i < arr.size(); i++) {
            if (firstOccurrence.find(arr[i]) == firstOccurrence.end()) {
                // If element is not in the map, store its first occurrence
                firstOccurrence[arr[i]] = i;
            } else {
                // If element is already in the map, calculate the distance
                int dist = i - firstOccurrence[arr[i]];
                maxDist = max(maxDist, dist); // Update the maximum distance
            }
        }
        
        return maxDist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends