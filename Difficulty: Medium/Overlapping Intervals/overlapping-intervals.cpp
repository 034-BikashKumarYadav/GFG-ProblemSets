//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
          sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int n = arr.size();
        
        for(int i=1; i<n; i++){
            int start = arr[i][0];
            int lastBack = ans.back()[1];
            if(start <= lastBack){
                ans.back()[1] = max(lastBack, arr[i][1]);
            }else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
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
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends