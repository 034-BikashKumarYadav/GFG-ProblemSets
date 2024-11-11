//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
          sort(arr.begin(),arr.end());
        int n = arr.size();
        int i = 0;
        int count = 0;
        int last = -1;
        for(int i=0;i<n;i++){
            if(last>=arr[i]){
                count = count + (last-arr[i])+1;
                last = arr[i] + (last-arr[i])+1;
            }
            else{
                last = arr[i];
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends