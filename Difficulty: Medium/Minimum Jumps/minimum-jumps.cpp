//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0]==0) return -1;
        int n=arr.size();
        if(n==1) return 0;
        int steps=0;
        int curr=0,prev=0;
        for(int i=0;i<n;i++){
            curr=max(curr,arr[i]+i);
            if(prev==i) steps++,prev=curr;
            if(prev>=n-1) return steps;
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends