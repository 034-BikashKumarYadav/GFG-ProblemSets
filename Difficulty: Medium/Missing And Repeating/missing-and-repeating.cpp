//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
            int repeat,miss;
        int n=arr.size();
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        for(int i=0;i<n+1;i++)
        {
            if(freq[i]==0 && i!=0)
            {
                miss=i;
                break;
            }        
        }
        for(int i=0;i<n+1;i++)
        {
            if(freq[i]>1)
            {
                repeat=i;
                break;
            }
        }
        return {repeat,miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends