//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    string P,Q;
    int sol(int x,int y){
        if(x==P.size() || y==Q.size()) return (P.size()-x) + (Q.size()-y);
        if(dp[x][y]!=INT_MAX) return dp[x][y];
        return dp[x][y] = P[x]==Q[y] ? sol(x+1,y+1):1+min(sol(x,y+1),min(sol(x+1,y),sol(x+1,y+1)));
    }
    int editDistance(string& s1, string& s2) {
        dp.assign(s1.size(), vector<int>(s2.size(), INT_MAX));
        P=s1,Q=s2;
        return sol(0,0);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends