//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        
       vector<pair<int,int>>vec; // stores { x^2 + y^2 , index } pairs
       vector<vector<int>>result; // result
       int ind = 0; 
       for(auto point : points) {
            vec.push_back({point[0]*point[0] + point[1]*point[1] , ind++});
       }
       // sort pairs in ascending order of squares 
       sort(begin(vec) , end(vec) , [](const pair<int,int>&a , const pair<int,int>&b) {
            if(a.first < b.first) {
                return a.first < b.first;
            } 
            return false;
       });
       
       // get the first 'k' and push into result
       for(int i = 0 ; i < k ; i++) { 
           int x = points[vec[i].second][0];
           int y = points[vec[i].second][1]; 
           vector<int>t = {x , y};
           result.push_back(t);
       }
      
      return result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends