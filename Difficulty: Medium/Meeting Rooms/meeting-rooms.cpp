//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    bool static compare(const vector<int>&a, const vector<int>&b){
       return a[0]<b[0];
    }
  public:
    bool canAttend(vector<vector<int>> &arr) {
          sort(arr.begin(),arr.end(),compare);
        int n=arr.size();
        bool attend=true;
        for(int i=1;i<n;i++){
            int currStart=arr[i][0];
            int prevEnd=arr[i-1][1];
            if(currStart<prevEnd) {
                attend=false;
                break;
            }
        }
        return attend;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends