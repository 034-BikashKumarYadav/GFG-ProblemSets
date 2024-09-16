//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string s) {
        // code here
           int n=s.size();
        unordered_map<int,int>m;//store index of sum
        m[0]=-1;
        int sum=0,ans=0;  
        for(int i=0;i<n;i++){
            if(s[i]=='(')sum++;
            else sum--;
            if(s[i]==')' and m.find(sum)!=m.end()){
                ans = max(ans,i-m[sum]);
            }
            else m[sum]=i;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends