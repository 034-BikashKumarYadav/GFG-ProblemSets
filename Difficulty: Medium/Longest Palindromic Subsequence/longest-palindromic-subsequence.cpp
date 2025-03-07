//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string a=A;
        reverse(A.begin(),A.end());
         string b=A;
        int m=a.size();
        int n=b.size();
        
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                 dp[i][j]=0;
                 else if(a[i-1]==b[j-1])
                  dp[i][j]=1+dp[i-1][j-1];
                  else
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][n];
        
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends