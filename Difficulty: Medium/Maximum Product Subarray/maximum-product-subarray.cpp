//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n=arr.size();
        long long  ans=arr[0];
	    long long  mx=arr[0];
	    long long  mn=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	          swap(mx,mn);
	       //  mx = max(static_cast<long long>(arr[i]), mx * static_cast<long long>(arr[i]));
             //mn = min(static_cast<long long>(arr[i]), mn * static_cast<long long>(arr[i]));
             long long temp=(long long)arr[i];
	         mx=max(temp,mx*temp);
	          mn=min(temp,mn*temp);
	         ans=max(ans,mx);
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
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends