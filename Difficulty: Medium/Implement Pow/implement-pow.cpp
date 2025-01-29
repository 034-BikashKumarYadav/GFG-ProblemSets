//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
          double ans=1;
        int nflag=0;
        if(e<0){
            nflag=1;
            e=-e;
        }
        while(e>0){
            if(e%2==1){
                ans=ans*b;
                e=e-1;
            }else{
                b=b*b;
                e=e/2;
            }
        }
        if(nflag==1){
           return double(1)/ans;
            
        }else{
         return ans;
        }
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends