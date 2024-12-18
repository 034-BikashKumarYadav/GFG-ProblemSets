//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isFeasible(vector<int>&arr, int k, int mid){
        int req = 1, sum = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(sum + arr[i] > mid){
                req++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        return (req<=k);
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        
        int sum = 0, mx = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            mx = max(mx, arr[i]);
        }
        int low = mx, high = sum, res = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(isFeasible(arr, k, mid)){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends