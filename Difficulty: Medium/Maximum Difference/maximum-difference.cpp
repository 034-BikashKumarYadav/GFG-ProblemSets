//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    void PSE(vector<int>&arr,vector<int>&pse){
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            
            // pse[i]=0 ? st.empty() : st.top();
            if(!st.empty()) pse[i]=st.top();
            
            st.push(arr[i]);
        }
    }
    
    void NSE(vector<int>&arr,vector<int>&nse){
        int n=arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            
            // nse[i]=0 ? st.empty() : st.top();
            if(!st.empty()) nse[i]=st.top();
            
            st.push(arr[i]);
        }
    }
    
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        vector<int>pse(n,0);
        vector<int>nse(n,0);
        PSE(arr,pse);
        NSE(arr,nse);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,abs(pse[i]-nse[i]));
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends