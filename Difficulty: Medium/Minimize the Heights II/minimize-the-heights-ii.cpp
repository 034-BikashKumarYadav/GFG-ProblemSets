//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
         sort (arr.begin(),arr.end());
     int ans = arr[n-1]-arr[0];
    int x = 1;
       while (arr[x]-k < 0) x++;
     for (; x<n; x++) {
      int mn = min(arr[0]+k, arr[x]-k);
        int mx = max(arr[n-1]-k, arr[x-1]+k);
        ans = min(mx-mn, ans);
}
return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends