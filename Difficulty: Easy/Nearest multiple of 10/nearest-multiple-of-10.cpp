//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.length();
        if(str[n-1]=='0') return str;   
        else if(str[n-1]<'6') {
            str[n-1]='0'; return str;
        }
        str[n-1]='0';
        int ind=n-2;
        while(ind>=0 and str[ind]=='9') {
            str[ind]='0';
            ind--;
        }
        if(ind<0) return '1'+str;
        str[ind]++;
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends