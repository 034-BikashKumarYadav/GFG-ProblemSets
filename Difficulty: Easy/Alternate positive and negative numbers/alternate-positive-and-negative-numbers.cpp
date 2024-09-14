//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here\
         vector<int>pos,neg;
	    int n=arr.size();
	      vector<int>pos,neg;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	         pos.push_back(arr[i]);
	         else
	         neg.push_back(arr[i]);
	    }
	 
	   int i = 0;
        int x = 0;
        int y = 0;
        while(x < neg.size() && y < pos.size()){
            arr[i] = pos[y];
            y++;
            i++;
            arr[i] = neg[x];
            x++;
            i++;
            
        }
        while(x < neg.size()){
            arr[i] = neg[x];
            x++;
            i++;
        }
        while(y < pos.size()){
            arr[i] = pos[y];
            y++;
            i++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends