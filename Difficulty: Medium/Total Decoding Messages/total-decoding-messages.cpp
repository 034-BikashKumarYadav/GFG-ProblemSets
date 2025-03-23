//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findWays(string& digits, int i, vector<int>& dp) {
        if(i == digits.length()){
            return 1;
        } 
        if(digits[i] == '0'){
            return 0;  
        } 
        if (dp[i] != -1){
            return dp[i];
        } 

        int oneDigit = findWays(digits, i + 1, dp); 
        int twoDigit = 0;

        if(i + 1 < digits.length()) {
            int num = stoi(digits.substr(i, 2));
            if(num >= 10 && num <= 26) {
                twoDigit = findWays(digits, i + 2, dp); 
            }
        }

        return dp[i] = oneDigit + twoDigit;
    }

    int countWays(string &digits) {
        if(digits.empty()) return 0; 
        vector<int> dp(digits.length(), -1);
        return findWays(digits, 0, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends