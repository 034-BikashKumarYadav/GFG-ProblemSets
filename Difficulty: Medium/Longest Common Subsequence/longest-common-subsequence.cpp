//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   
       int dp[1001][1001];
      int solve(int ind1,string &s1,int ind2,string &s2)
      {
            if(ind1<0 || ind2<0)
             return 0;
             
              if(dp[ind1][ind2]!=-1)
                return dp[ind1][ind2];
                
             if(s1[ind1]==s2[ind2])
                return dp[ind1][ind2]=1+solve(ind1-1,s1,ind2-1,s2);
                
           return dp[ind1][ind2]=max(solve(ind1-1,s1,ind2,s2),solve(ind1,s1,ind2-1,s2));
      }
   
    int lcs(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
         memset(dp,-1,sizeof(dp));
         return solve(n-1,s1,m-1,s2);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends